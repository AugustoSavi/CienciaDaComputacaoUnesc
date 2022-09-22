var express = require('express');
var app = express();

app.use(express.static('public'));
app.use(express.json());
app.use(express.urlencoded({
    extended: true
}));

app.post('/novo-heroi', function (req, res) {
    console.log(req.body);
    res.redirect('/');
});


var server = app.listen(5000);