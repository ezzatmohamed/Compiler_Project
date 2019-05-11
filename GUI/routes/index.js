const express = require('express');
var upload = require('express-fileupload');
var formidable = require('formidable');
const router = express.Router();
var fs = require("fs");
var exec = require("child_process").exec;

//welcome page
router.get('/', (req,res)=> res.render('welcome'));




//Running 
router.get('/errors', function(req,res) {
  fs.readFile("Results/errors.txt", function(err, buf)
  {
    var data = buf.toString();

    res.render('errors',{data})

  });

});
/*<% var data1 = data %>
            <% var i = 0 %>
            <% var words = data1.split("\n")%>
            <% for(i = 0; i < words.length; i++) {%>
                <% var words2 = words.split(" ")%>
                <% for(j = 0; j < words2.length; j+=2 {%>
                <h4 class="card-title"><%= words2[j]+' '+ words2[j+1] %></h4>
                <p class="card-text"></p>
            <% }%>
            <% }%>*/ 

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

router.post('/submit', function(req,res) 
{
  var data = req.body.testcase;
  fs.writeFileSync(__dirname + "/../uploads/program.txt", data);
  //run command for yacc  # ./output > qd
  exec('./../src/output', function(err, stdout, stderr)
  {
    console.log(stdout);
    process.stdout.write();
      
    });
    
    res.render('welcome');
    /*
  fs.writeFile  (__dirname + "/../uploads/program.txt", data, function(err){
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
  });*/
});



module.exports = router;