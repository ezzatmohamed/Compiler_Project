const express = require('express');
const app = express();
const expressLayouts = require('express-ejs-layouts');
//const mongoose = require('mongoose');
var upload = require('express-fileupload');



//DB Config
//const db = require('./config/keys').MongoURI;

//Connect to Mongo
//mongoose.connect(db, { useNewUrlParser: true })
//    .then(() => console.log('MongoDB Connected...'))
//    .catch(err => console.log(err));

//EJS
app.use(expressLayouts);
app.set('view engine','ejs');


//Bodyparser
app.use(express.urlencoded({ extended: false}));


//Routes
app.use('/', require('./routes/index'));

const PORT = process.env.PORT || 5000;

app.listen(PORT,console.log(`Server started on port ${PORT}`));

app.use(upload()); // configure middleware

