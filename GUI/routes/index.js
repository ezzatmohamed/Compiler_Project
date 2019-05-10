const express = require('express');
var upload = require('express-fileupload');
var formidable = require('formidable');
const router = express.Router();
var fs = require("fs");
var exec = require("child_process").exec;

//User model
const User = require('../models/User');
//welcome page
router.get('/', (req,res)=> res.render('welcome'));




//Running 
//Put command instead of mkdir Nanoos
router.get('/about', function(req,res, next){
  exec('mkdir Nanoos', function(err, stdout, stderr){
    console.log(stdout);
    process.stdout.write();
    
  })
  
});

fs.readFile("intercode.txt", function(err, buf) {
  //console.log(buf.toString());
  var data = buf.toString();
//

//console.log(data);
//console.log("^C");
router.get('/code', (req,res)=> res.render('intermediatecode',{data}));
});

fs.readFile("intercode.txt", function(err, buf) {
  //console.log(buf.toString());
  var data = buf.toString();


console.log(data);
router.get('/table', (req,res)=> res.render('symboltable',{data}));
});

router.use(upload());
//router.use(formidable());
router.post('/upload' ,(req,res)=> {

    //console.log(req.files) 
    if(req.files.upfile){
      //  res.send('hello');
        var file = req.files.upfile,
          name = "intercode.txt",
          type = file.mimetype;
        var uploadpath = "C:/Users/NancyAlarabawy/GUI/" + name;
        file.mv(uploadpath,function(err){
          if(err){
            console.log("File Upload Failed",name,err);
            res.send("Error Occured!")
          }
          else {
            console.log("File Uploaded",name);
            //run command for yacc  # ./output > qd
            exec('mkdir Nanoos', function(err, stdout, stderr){
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
  fs.writeFile("intercode.txt", data, (err) => {
    if (err) console.log(err);
    console.log("Successfully Written to File.");
    //res.send("Successfully Written to File.");
    res.render('welcome');
  });
});



module.exports = router;