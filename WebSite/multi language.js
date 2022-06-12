// define language anchors
var dataReload = document.querySelectorAll("[data-reload]");

// Language translations
var language = {
    eng: {
      welcome: "Welcome everyone!"
    }, 
    bg: {
      welcome: "Здравейте всички!"
    }
};

// define language via window hash
if (window.location.hash) {
    if (window.location.hash === "#bg") {
        hi.textContent = language.bg.welcome;
    }
}

// define language reload onclick illeteration
for (i = 0; i <= dataReload.length; i++) {
    dataReload[i].onclick = function() {
        location.reload(true);
    };
}