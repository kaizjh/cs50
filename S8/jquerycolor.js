$(document).ready(function(){
    $('j.jQButton').click(function(){
        $('#colorDiv').css('background-color', this.innerHTML.toLowerCase());
    });
});
