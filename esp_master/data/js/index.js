const badgeTV = document.getElementById('badge-tv');
const badgeAC = document.getElementById('badge-ac');

async function onDevice(device) {
    try {
        const response = await fetch("http://192.168.100.140/api/control", {
            method: 'POST',
            headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
            body: `state=on&device=${device}`
        });
        const result = await response.json();
        console.log(result);
        if (result.status != 'OK') {
            throw new Error(result.message);
        }
        if (device == 'tv') badgeTV.style.backgroundColor = "green";
        if (device == 'ac') badgeAC.style.backgroundColor = "green";
    } catch (error) {
        throw new Error(error.message);
    }
}

async function offDevice(device) {
    try {
        const response = await fetch("http://192.168.100.140/api/control", {
            method: 'POST',
            headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
            body: `state=off&device=${device}`
        });
        const result = await response.json();
        console.log(result);
        if (result.status != 'OK') {
            throw new Error(result.message);
        }
        if (device == 'tv') badgeTV.style.backgroundColor = "red";
        if (device == 'ac') badgeAC.style.backgroundColor = "red";
    } catch (error) {
        throw new Error(error.message);
    }
}