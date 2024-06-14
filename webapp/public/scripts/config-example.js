// Rename this file to config.js and replace values below with Firebase config object

const firebaseConfig = {
    apiKey: "apiKey",
    authDomain: "authDomain",
    databaseURL: "databaseURL",
    projectId: "projectId",
    storageBucket: "storageBucket",
    messagingSenderId: "messagingSenderId",
    appId: "appId"
};

// Initialize firebase
firebase.initializeApp(firebaseConfig);

// Make auth and database references
const auth = firebase.auth();
const db = firebase.database();