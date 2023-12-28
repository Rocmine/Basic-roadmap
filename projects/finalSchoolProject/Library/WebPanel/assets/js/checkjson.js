let lastModified;

function checkForChanges() {
    fetch('data.json', { method: 'HEAD' })
        .then(response => {
            const currentLastModified = response.headers.get('Last-Modified');
            if (lastModified && currentLastModified !== lastModified) {
                location.reload(true);
            }
            lastModified = currentLastModified;
        })
        .catch(error => console.error('Error fetching data.json:', error));
}

setInterval(checkForChanges, 1000);
