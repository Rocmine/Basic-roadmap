const jsonFileUrl = "/data.json";

// Function to get URL parameters
function getVolId() {
  const urlParams = new URLSearchParams(window.location.search);
  const parameters = {};

  for (const [key, value] of urlParams.entries()) {
    parameters[key] = value;
  }

  return parameters;
}

const flightId = getVolId().id;

if (flightId) {
  fetch(jsonFileUrl)
    .then((response) => {
      if (!response.ok) {
        throw new Error(`Network response was not ok: ${response.statusText}`);
      }
      return response.json();
    })
    .then((data) => {
      const index = getVolId().id;
      const flight = data.flights[index];
      document.getElementById("volid").textContent = flight.volId;

      if (flight) {
        const tableBody = document.querySelector("table");
        if (flight.vPassager) {
          flight.vPassager.forEach((passenger) => {
            const newRow = document.createElement("tr");
            newRow.innerHTML = `
              <td>${passenger.idPass}</td>
              <td>${passenger.nom} </td>
              <td>${passenger.prenom}</td>
              <td>${passenger.age}</td>
              <td>${passenger.tele}</td>
              <td>${passenger.adresse}</td>
            `;
  
            tableBody.appendChild(newRow);
          });
        }
        else {
          const newRow = document.createElement("tr");
            newRow.innerHTML = `
              <td colspan="6">Pas de passagers</td>
            `;
  
            tableBody.appendChild(newRow);
        }
      } else {
        alert("Flight not found");
      }
    })
    .catch((error) => {
      console.error("Error fetching the JSON file:", error);
      alert("501: Internal Error");
      window.location.href = "/";
    });
} else {
  alert("Flight ID not provided in the URL");
  window.location.href = "/";
}
