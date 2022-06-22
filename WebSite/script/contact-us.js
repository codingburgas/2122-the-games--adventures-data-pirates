/*Contact us form (Works only if the data is correctly typed by the SMPT(Simple Mail Transfer Protocol); Used )*/

function sendEmail(){
    Email.send({
        SecureToken: "3c30919e-59be-4155-906e-fbcf944d2250",
        To : 'datapirates.contact@gmail.com',
        From : document.getElementById("email").value,
        Subject : "New Contact From Enquiry",
        Body : "Name: " + document.getElementById("name").value
            + "<br> Email: " + document.getElementById("email").value
            + "<br> Phone Number: " + document.getElementById("phone").value
            + "<br> Message: " + document.getElementById("message").value
    }).then(
    message => alert("Message Sent Succesfully")
    );
}