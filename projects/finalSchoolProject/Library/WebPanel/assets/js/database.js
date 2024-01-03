var jsonFileUrl = new URL('data.json', window.location.href).href;


fetch(jsonFileUrl)
  .then((response) => {
    if (!response.ok) {
      throw new Error(`Network response was not ok: ${response.statusText}`);
    }
    return response.json();
  })
  .then((data) => {

    const tableBody = document.querySelector("table");

    if (data.flights) {
      data.flights.forEach((flight, index) => {
        const newRow = document.createElement("tr");
        newRow.innerHTML = `
        <tr>
            <td>${index}</td>
            <td>${flight.avion.modele}</td>
            <td><a href="./plane.html?id=${index}"><i class="fa-solid fa-circle-info"></i></a></td>
            <td>${flight.dateDep.days + "/" + flight.dateDep.month + "/" + flight.dateDep.year}</td>
            <td>${flight.dateAr.days + "/" + flight.dateAr.month + "/" + flight.dateAr.year}</td>
            <td>
              <a href="./passagers.html?id=${index}"><i class="fa-solid fa-list"></i> Liste</a>
            </td>
            </tr>
          `;
  
        tableBody.appendChild(newRow);
      });
    } else {
      const newRow = document.createElement("tr");
        newRow.innerHTML = `
        <tr>
            <td colspan="6">Aucun Vol existe</td>
            </tr>
          `;
  
        tableBody.appendChild(newRow);
    }
  })
  .catch((error) => {
    console.error("Error fetching the JSON file:", error);
    alert("501: Internal Error")
    // window.location.href = "/";
  });
