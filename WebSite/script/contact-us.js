/*Resetting the form after submition*/
document.getElementById("Form").reset();

/*Validation rules(not enough skills to make)*/
{
const name = document.getElementById('name')
const phone = document.getElementById('phone')
const email = document.getElementById('email')
const message = document.getElementById('message')
const errorElement = document.getElementById('error')

form.addEventListener('submit', (e) => {
  let messages = []
  if (name.value === '' || name.value == null) {
    messages.push('Name is required')
  }

  if (phone.value === '' || phone.value == null) {
    messages.push('Phone number is required')
  }

  if (email.value === '' || email.value == null) {
    messages.push('Email is required')
  }

  if (message.value === '' || message.value == null) {
    messages.push('Text is required')
  }
  if (messages.length > 0) {
    e.preventDefault()
    errorElement.innerText = messages.join(', ')
  }
})
}
