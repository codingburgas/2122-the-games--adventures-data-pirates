/*Changes between light and dark theme*/

var icon = document.getElementById("icon");

icon.onclick = function(){
    document.body.classList.toggle("dark-theme");
    if(document.body.classList.contains("dark-theme")){
        icon.src = "../assets/images/sun.png";
    }else{
        icon.src = "../assets/images/moon.png";
    }
}
