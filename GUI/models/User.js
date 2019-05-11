const mongoose = require('mongoose');
const fs = require('fs');

const FileSchema = new mongoose.Schema({
    name: {
        type: fs,
        required: true
    },
    
    date: {
        type: Date,
        default: Date.now
    }

});

const Files = mongoose.model('Files', FileSchema);

module.exports = Files;