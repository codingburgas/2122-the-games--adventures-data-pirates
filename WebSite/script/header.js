/* When the user scrolls down, hide the navbar. When the user scrolls up, show the navbar */
// Enable hidden nav bar
{
  const nav = document.querySelector(".nav");
  let lastScrollY = window.scrollY;

  window.addEventListener("scroll", () => {
    if (lastScrollY < window.scrollY) {
      nav.classList.add("nav--hidden");
    } else {
      nav.classList.remove("nav--hidden");
    }

    lastScrollY = window.scrollY;
  });
}