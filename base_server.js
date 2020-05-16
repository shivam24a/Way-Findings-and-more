var express = require("express")
app = express();
var bodyParser = require("body-parser");
app.use(express.static("public"));

app.use(bodyParser.urlencoded({ extended: true }));


app.get('/', function(req, res) {
    res.render('index.ejs');
})

app.post('/map', function(req, res) {
    res.render("map.ejs");
    // res.send("okkk");
});


app.post('/cross', function(req, res) {
    console.log(req.body["data"]);
    res.render('cross.ejs', { data: req.body["data"] });

});

app.post('/wayfinding', function(req, res) {
    res.render('way_finding_map1.ejs', { v_to: "room1", v_from: "room2" });
})

app.post('/way_finding_map2', function(req, res) {
    res.render('way_finding_map2.ejs', { v_to: "room1", v_from: "room2" });
})
app.post('/way_finding_map1', function(req, res) {
    res.render('way_finding_map1.ejs', { v_to: "room1", v_from: "room2" });
})



app.post('/commercial_information', function(req, res) {
    res.render('commercial_information.ejs');
})

app.get('/commercial_information/hotel', function(req, res) {
    res.render('commercial_information/hotel.ejs');
})
app.get('/commercial_information/hospitals', function(req, res) {
    res.render('commercial_information/hospitals.ejs');
})
app.get('/commercial_information/mall', function(req, res) {
    res.render('commercial_information/mall.ejs');
})
app.get('/commercial_information/medical', function(req, res) {
    res.render('commercial_information/medical.ejs');
})
app.get('/commercial_information/restaurant', function(req, res) {
    res.render('commercial_information/restaurant.ejs');
})
app.get('/commercial_information/travel', function(req, res) {
    res.render('commercial_information/travel.ejs');
})




app.listen(3000, function() {
    console.log("welcome to Public-Dashboard is working");
})
