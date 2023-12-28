const loader = document.querySelector("#loader");
loader.innerHTML = `
<i class="fa-solid fa-plane"></i>
<h1>Loading app, getting ready...<br><span>Coded by Ayoub Majid & Rochdi Mohamed Amine</span></h1>
`;

window.addEventListener("load", function () {
  setTimeout(function () {
    document.getElementById('loader').style.filter = "opacity(0)";
    setTimeout(() => {
      document.getElementById('loader').style.display = "none";
    }, 1000);
  }, 1000);
});
