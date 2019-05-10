const express = require('express');
const app = express();
const expressLayouts = require('express-ejs-layouts');
const mongoose = require('mongoose');
var upload = require('express-fileupload');
/*const flash = require('connect-flash');
const session = require('express-session');

*/


//DB Config
const db = require('./config/keys').MongoURI;

//Connect to Mongo
mongoose.connect(db, { useNewUrlParser: true })
    .then(() => console.log('MongoDB Connected...'))
    .catch(err => console.log(err));

//EJS
app.use(expressLayouts);
app.set('view engine','ejs');


//Bodyparser
app.use(express.urlencoded({ extended: false}));

// Express Session middleware
/*app.use(session({
    secret: 'secret',
    resave: true,
    saveUninitialized: true,
  }));*/

  //Connect flash middleware
//app.use(flash());

//Global vars
/*app.use((req, res, next) => {
    res.locals.success_msg = req.flash('success_msg');
    res.locals.error_msg = req.flash('error_msg');
    res.locals.error = req.flash('error');
    next();
});*/

//Routes
app.use('/', require('./routes/index'));

const PORT = process.env.PORT || 5000;

app.listen(PORT,console.log(`Server started on port ${PORT}`));

app.use(upload()); // configure middleware

/*
  Aman Kharbanda
  Subscribe my channel for more videos
  https://goo.gl/H91NRo
  Thanks!
*/
/*
const express = require('express');
var app = express();
var upload = require('express-fileupload');
const http = require('http');
http.Server(app).listen(5000); // make server listen on port 80

app.use(upload()); // configure middleware

console.log("Server Started at port 5000");

app.get('/',function(req,res){
  res.sendFile(__dirname+'/index.html');
})
app.post('/upload',function(req,res){
  console.log(req.files);
  if(req.files.upfile){
    var file = req.files.upfile,
      name = file.name,
      type = file.mimetype;
    var uploadpath = __dirname + '/uploads/' + name;
    file.mv(uploadpath,function(err){
      if(err){
        console.log("File Upload Failed",name,err);
        res.send("Error Occured!")
      }
      else {
        console.log("File Uploaded",name);
        res.send('Done! Uploading files')
      }
    });
  }
  else {
    res.send("No File selected !");
    res.end();
  };
})*/
