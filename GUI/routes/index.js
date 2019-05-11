const express = require('express');
var upload = require('express-fileupload');
var formidable = require('formidable');
const router = express.Router();
var fs = require("fs");
var exec = require("child_process").exec;

//welcome page
router.get('/', (req,res)=> res.render('welcome'));




//Running 
router.get('/about', function(req,res, next){
  exec('mkdir Nanoos', function(err, stdout, stderr){
    console.log(stdout);
    process.stdout.write();
    
  })
  
});


router.get('/code', function(req,res)
{
  fs.readFile("Results/quad.txt", function(err, buf)
  {
    
    var data = buf.toString();

    res.render('intermediatecode',{data})

  });
});



router.get('/table', function(req,res) 
{
  fs.readFile("Results/symbol.txt", function(err, buf) 
  {

    var symbols = buf.toString();
    
    res.render('symboltable',{symbols});
    console.log(symbols);
  });
});



router.use(upload());
//router.use(formidable());
router.post('/upload' ,(req,res)=> {

    //console.log(req.files) 
    if(req.files.upfile){
      //  res.send('hello');
        var file = req.files.upfile,
          name = "program.txt",
          type = file.mimetype;

        var uploadpath = __dirname + "/../uploads/program.txt";
        file.mv(uploadpath,function(err){
          if(err)
          {
            console.log("File Upload Failed",name,err);
            res.send("Error Occured!")
          }
          else {
            console.log("File Uploaded",name);
            //run command for yacc  # ./output > qd
            exec('./../src/output', function(err, stdout, stderr){
            console.log(stdout);
            process.stdout.write();
              
            })
            //res.send('Done! Uploading files') 
            res.render('welcome');
          }
        });
      }
      else {
        res.send("No File selected !");
        res.end();
      };
      //res.send("File Uploaded");*/
});

router.post('/submit', (req,res)=> {
  var data = req.body.testcase;
  fs.writeFile(__dirname + "/../uploads/program.txt", data, function(err){
    if(err)
    {
      console.log("File Upload Failed",name,err);
      res.send("Error Occured!")
    }
    else 
    {
      //run command for yacc  # ./output > qd
      exec('./../src/output', function(err, stdout, stderr){
      console.log(stdout);
      process.stdout.write();
        
      })
      //res.send('Done! Uploading files') 
      res.render('welcome');
    }
  });
});



module.exports = router;