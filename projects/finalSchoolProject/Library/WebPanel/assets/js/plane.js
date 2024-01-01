const jsonFileUrl = new URL('data.json', window.location.href).href;
fetch(jsonFileUrl)
  .then((response) => {
    if (!response.ok) {
      throw new Error(`Network response was not ok: ${response.statusText}`);
    }
    return response.json();
  })
  .then((data) => {
    const card = document.querySelector(".plane-card");
    const query = getPlaneCode();
    card.querySelector("#pIdVol").textContent = query.id;

    // Display plane data on the webpage
    displayPlaneData(card, data.flights[query.id].avion);
  })
  .catch((error) => {
    console.error("Error fetching the JSON file:", error);
    alert("501: Internal Error");
    window.location.href = "/";
  });

function getPlaneCode() {
  const urlParams = new URLSearchParams(window.location.search);
  const parameters = {};

  for (const [key, value] of urlParams.entries()) {
    parameters[key] = value;
  }

  return parameters;
}

function displayPlaneData(card, planeData) {
  card.querySelector("#pCode").innerText = planeData.codeAv;
  card.querySelector("#pModel").innerText = planeData.modele;
  card.querySelector("#pPilot").innerText = planeData.pilote;
  card.querySelector("#pCapacity").innerText = planeData.capacite;
  card.querySelector("#pFab").innerText = planeData.dateFab.days + "/" + planeData.dateFab.month + "/" + planeData.dateFab.year;
  card.querySelector("#pVolNum").innerText = planeData.nbrVols;
}
