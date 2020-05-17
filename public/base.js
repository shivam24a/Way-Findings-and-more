window.onload = setInterval(clock, 1000);

function clock() {
    var d = new Date();
    var date = d.getDate();
    var month = d.getMonth();
    var montharr = ["Jan", "Feb", "Mar", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"];
    month = montharr[month];
    var year = d.getFullYear();
    var day = d.getDay();
    var dayarr = ["Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"];
    day = dayarr[day];
    var hour = d.getHours();
    var min = d.getMinutes();
    var sec = d.getSeconds();
    document.getElementById("date").innerHTML = day + " " + date + " " + month + " " + year;
    var mm, ng;
    if (hour > 11) mm = " PM", ng = 12;
    else mm = " AM", ng = 0;

    hour=hour-ng;
    if(hour<10) hour="0"+hour;
    if(min<10) min="0"+min;
    if(sec<10) sec="0"+sec;
    
    document.getElementById("time").innerHTML =hour  + " : " + min + " : " + sec + mm;
}


function req(where){
     var data = {};
        var title = $('input[name=quote]').val();
        data.ab = title;
        $.ajax({
            type: 'post',
            url: where,
            data: data,
        }).done(function(res){
            // alert("ok");
            $('#screen').html(res);
        });
}

req('/map');
$(document).ready(function() {
    $("form#map").on('submit', function(e) {
        e.preventDefault();
        req('/map');
    });
});

$(document).ready(function() {
    $("form#commercial_information").on('submit', function(e) {
        e.preventDefault();
        req('/commercial_information');
    });
});

$(document).ready(function() {
    $("form#wayfinding").on('submit', function(e) {
        e.preventDefault();
        req('/way_finding_map1');
    });
});



