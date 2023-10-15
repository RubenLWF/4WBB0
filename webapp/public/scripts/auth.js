auth.onAuthStateChanged(user => {
    if (user) {
        setupUI(user);
        var uid = user.uid;
    } else {
        setupUI();
    }
});

const loginForm = document.querySelector('#login-form');
loginForm.addEventListener('submit', (e) => {
    e.preventDefault();

    const email = loginForm['input-email'].value;
    const password = loginForm['input-password'].value;

    auth.signInWithEmailAndPassword(email, password).then((cred) => {
        loginForm.reset();
    })
        .catch((error) => {
            const errorCode = error.code;
            const errorMessage = error.message;
            document.getElementById("error-message").innerHTML = errorMessage;
        });
});

const logout = document.querySelector('#logout-link');
logout.addEventListener('click', (e) => {
    e.preventDefault();
    auth.signOut();
});