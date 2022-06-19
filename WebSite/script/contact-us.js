/*Contact us form (Works only if the data is correctly typed by the SMPT )*/
src="https://smtpjs.com/v3/smtp.js"

function sendEmail(){
    Email.send({
        SecureToken: "6cb07f4e-7643-4ee6-95ce-8b0fd5e3f8e6",
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
