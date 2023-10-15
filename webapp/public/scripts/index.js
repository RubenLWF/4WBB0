const loginElement = document.querySelector('#login-form');
const contentElement = document.querySelector("#content-sign-in");
const userDetailsElement = document.querySelector('#user-details');
const authBarElement = document.querySelector("#authentication-bar");

// Elements for sensor readings
const inTempElement = document.getElementById("inTemp");
const outTempElement = document.getElementById("outTemp");
const sunIntensElement = document.getElementById("sunIntens");
const blindsOpenElement = document.getElementById("blindsOpen")
const blindsOpenLabelElement = document.getElementById("blindsOpenLabel");
const openCardElement = document.getElementById("openCard");
const blindsOpenHintElement = document.getElementById("blindsOpenHint");
const targetTempElement = document.getElementById("tTemp");
const targetTempIncreaseElement = document.getElementById("tTempUp");
const targetTempDecreaseElement = document.getElementById("tTempDown");

// MANAGE LOGIN/LOGOUT UI
const setupUI = (user) => {
    if (user) {
        //toggle UI elements
        loginElement.style.display = 'none';
        contentElement.style.display = 'block';
        authBarElement.style.display = 'block';
        userDetailsElement.style.display = 'block';
        userDetailsElement.innerHTML = user.email;

        // get user UID to get data from database
        var uid = user.uid;

        // Database paths (with user UID)
        var dbPathInsideTemp = 'UsersData/' + uid.toString() + '/insideTemperature';
        var dbPathOutsideTemp = 'UsersData/' + uid.toString() + '/outsideTemperature';
        var dbPathLightIntensity = 'UsersData/' + uid.toString() + '/lightIntensity';
        var dbPathBlindsOpen = 'UsersData/' + uid.toString() + '/blindsOpen';
        var dbPathTargetTemp = 'UsersData/' + uid.toString() + '/targetTemperature';
        var dbpathWrite = 'UsersData/' + uid.toString();

        // Database references
        var dbRefInsideTemp = firebase.database().ref().child(dbPathInsideTemp);
        var dbRefOutsideTemp = firebase.database().ref().child(dbPathOutsideTemp);
        var dbRefLightIntensity = firebase.database().ref().child(dbPathLightIntensity);
        var dbRefBlindsOpen = firebase.database().ref().child(dbPathBlindsOpen);
        var dbRefTargetTemp = firebase.database().ref().child(dbPathTargetTemp);
        var dbRefWrite = firebase.database().ref().child(dbpathWrite);

        // Update page with new readings
        dbRefInsideTemp.on('value', snap => {
            inTempElement.innerText = (snap.val() / 10).toFixed(1);
        });

        dbRefOutsideTemp.on('value', snap => {
            outTempElement.innerText = (snap.val() / 10).toFixed(1);
        });

        dbRefLightIntensity.on('value', snap => {
            sunIntensElement.innerText = (snap.val() / 10).toFixed(1);
        });

        dbRefTargetTemp.on('value', snap => {
            targetTempElement.innerText = (snap.val() / 10).toFixed(1);
        });

        dbRefBlindsOpen.on('value', snap => {
            blindsOpenElement.checked = snap.val();
            if (snap.val()) {
                blindsOpenLabelElement.innerText = "Open";
                openCardElement.style.backgroundColor = "white";
                openCardElement.style.color = "black";
                blindsOpenHintElement.innerText = "Press to close...";
            } else {
                blindsOpenLabelElement.innerText = "Closed";
                openCardElement.style.backgroundColor = "#353C40";
                openCardElement.style.color = "white";
                blindsOpenHintElement.innerText = "Press to open...";
            }
        });

        blindsOpenElement.addEventListener('change', function () {
            if (this.checked) {
                blindsOpenLabelElement.innerText = "Open";
                openCardElement.style.backgroundColor = "white";
                openCardElement.style.color = "black";
                blindsOpenHintElement.innerText = "Press to close...";
                dbRefWrite.update({
                    blindsOpen: true
                });

            } else {
                blindsOpenLabelElement.innerText = "Closed";
                openCardElement.style.backgroundColor = "#353C40";
                openCardElement.style.color = "white";
                blindsOpenHintElement.innerText = "Press to open...";
                dbRefWrite.update({
                    blindsOpen: false
                });
            }
        });

        targetTempIncreaseElement.addEventListener('click', function () {
            var tTemp = (parseFloat(targetTempElement.innerText) + 0.1).toFixed(1);
            targetTempElement.innerText = tTemp;
            dbRefWrite.update({
                targetTemperature: (tTemp * 10)
            });
        });

        targetTempDecreaseElement.addEventListener('click', function () {
            var tTemp = (parseFloat(targetTempElement.innerText) - 0.1).toFixed(1);
            targetTempElement.innerText = tTemp;
            dbRefWrite.update({
                targetTemperature: (tTemp * 10)
            });
        });

        // if user is logged out
    } else {
        // toggle UI elements
        loginElement.style.display = 'block';
        authBarElement.style.display = 'none';
        userDetailsElement.style.display = 'none';
        contentElement.style.display = 'none';
    }
}