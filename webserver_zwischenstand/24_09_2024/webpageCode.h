const char flashcardapp[] =
R"=====(
  <!DOCTYPE html>
<html lang="en">
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Flashcard App</title>
    <!-- Font Awesome Icons -->
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.1.2/css/all.min.css"
    />
    <!-- Google Fonts -->
    <link
      href="https://fonts.googleapis.com/css2?family=Poppins:wght@400;500;600&display=swap"
      rel="stylesheet"
    />
    <!-- Stylesheet -->
    
    <style>
        * {
    padding: 0;
    margin: 0;
    box-sizing: border-box;
    font-family: "Poppins", sans-serif;
  }
  
  body {
    background-color: #f7f9fd;
  }
  
  .container {
    width: 90vw;
    max-width: 62.5em;
    position: relative;
    margin: auto;
  }
  
  .add-flashcard-con {
    display: flex;
    justify-content: flex-end;
    padding: 1.2em 1em;
  }
  
  button {
    border: none;
    outline: none;
    cursor: pointer;
  }
  
  .add-flashcard-con button {
    font-size: 1em;
    background-color: #4caf50; /* Updated color */
    color: #ffffff;
    padding: 0.8em 1.2em;
    font-weight: 500;
    border-radius: 0.4em;
  }
  
  #card-con {
    margin-top: 1em;
  }
  
  .question-container {
    width: 90vw;
    max-width: 34em;
    display: flex;
    flex-direction: column;
    justify-content: center;
    background-color: #ffffff;
    position: absolute;
    transform: translate(-50%, -50%);
    top: 50%;
    left: 50%;
    padding: 3em 2em;
    border-radius: 0.6em;
    box-shadow: 0 1em 2em rgba(28, 0, 80, 0.1);
  }
  
  .question-container h2 {
    font-size: 2.2em;
    color: #363d55;
    font-weight: 600;
    text-align: center;
    margin-bottom: 2em;
  }
  
  .wrapper {
    display: grid;
    grid-template-columns: 11fr 1fr;
    gap: 1em;
    margin-bottom: 1em;
  }
  
  .error-con {
    align-self: center;
  }
  
  #error {
    color: #ff5353;
    font-weight: 400;
  }
  
  .fa-xmark {
    font-size: 1.4em;
    background-color: #4caf50; /* Updated color */
    height: 1.8em;
    width: 1.8em;
    display: grid;
    place-items: center;
    color: #ffffff;
    border-radius: 50%;
    cursor: pointer;
    justify-self: flex-end;
  }
  
  label {
    color: #363d55;
    font-weight: 600;
    margin-bottom: 0.3em;
  }
  
  textarea {
    width: 100%;
    padding: 0.7em 0.5em;
    border: 1px solid #d0d0d0;
    outline: none;
    color: #414a67;
    border-radius: 0.3em;
    resize: none;
  }
  
  textarea:not(:last-child) {
    margin-bottom: 1.2em;
  }
  
  textarea:focus {
    border-color: #363d55;
  }
  
  #save-btn {
    font-size: 1em;
    background-color: #4caf50; /* Updated color */
    color: #ffffff;
    padding: 0.6em 0;
    border-radius: 0.3em;
    font-weight: 600;
  }
  
  .card-list-container {
    display: grid;
    padding: 0.2em;
    gap: 1.5em;
    grid-template-columns: 1fr 1fr 1fr;
  }
  
  .card {
    background-color: #ffffff;
    box-shadow: 0 0.4em 1.2em rgba(28, 0, 80, 0.08);
    padding: 1.2em;
    border-radius: 0.4em;
  }
  
  .question-div,
  .answer-div {
    text-align: justify;
  }
  
  .question-div {
    margin-bottom: 0.5em;
    font-weight: 500;
    color: #363d55;
  }
  
  .answer-div {
    margin-top: 1em;
    font-weight: 400;
    color: #414a67;
  }
  
  .show-hide-btn {
    display: block;
    background-color: #4caf50; /* Updated color */
    color: #ffffff;
    text-decoration: none;
    text-align: center;
    padding: 0.6em 0;
    border-radius: 0.3em;
  }
  
  .buttons-con {
    display: flex;
    justify-content: flex-end;
  }
  
  .edit,
  .delete {
    background-color: transparent;
    padding: 0.5em;
    font-size: 1.2em;
  }
  
  .edit {
    color: #4caf50; /* Updated color */
  }
  
  .delete {
    color: #ff5353;
  }
  
  .hide {
    display: none;
  }
  
  @media screen and (max-width: 800px) {
    .card-list-container {
      grid-template-columns: 1fr 1fr;
      gap: 0.8em;
    }
  }
  
  @media screen and (max-width: 450px) {
    body {
      font-size: 14px;
    }
    .card-list-container {
      grid-template-columns: 1fr;
      gap: 1.2em;
    }
  }
    </style>
  </head>
  <body>
    <div class="container">
      <div class="add-flashcard-con">
        <button id="add-flashcard">Add Flashcard</button>
      </div>

      <!-- Display Card of Question And Answers Here -->
      <div id="card-con">
        <div class="card-list-container"></div>
      </div>
    </div>

    <!-- Input form for users to fill question and answer -->
    <div class="question-container hide" id="add-question-card">
      <h2>Add Flashcard</h2>
      <div class="wrapper">
        <!-- Error message -->
        <div class="error-con">
          <span class="hide" id="error">Input fields cannot be empty!</span>
        </div>
        <!-- Close Button -->
        <i class="fa-solid fa-xmark" id="close-btn"></i>
      </div>

      <label for="question">Question:</label>
      <textarea
        class="input"
        id="question"
        placeholder="Type the question here..."
        rows="2"
      ></textarea>
      <label for="answer">Answer:</label>
      <textarea
        class="input"
        id="answer"
        rows="4"
        placeholder="Type the answer here..."
      ></textarea>
      <button id="save-btn">Save</button>
    </div>

    <!-- Script -->
    <script>
                // Selecting DOM elements
        const container = document.querySelector(".container");
        const addQuestionCard = document.getElementById("add-question-card");
        const cardButton = document.getElementById("save-btn");
        const question = document.getElementById("question");
        const answer = document.getElementById("answer");
        const errorMessage = document.getElementById("error");
        const addQuestion = document.getElementById("add-flashcard");
        const closeBtn = document.getElementById("close-btn");

        // Initializing variables
        let editBool = false;
        let originalId = null;
        let flashcards = JSON.parse(localStorage.getItem('flashcards')) || [];

        addQuestion.addEventListener("click", () => {
        // Show the add question card and hide the container
        container.classList.add("hide");
        question.value = "";
        answer.value = "";
        addQuestionCard.classList.remove("hide");
        });

        closeBtn.addEventListener("click", () => {
        // Close the add question card and show the container
        container.classList.remove("hide");
        addQuestionCard.classList.add("hide");
        if (editBool) {
            editBool = false;
        }
        });

        cardButton.addEventListener("click", () => {
        // Save the flashcard
        let tempQuestion = question.value.trim();
        let tempAnswer = answer.value.trim();
        if (!tempQuestion || !tempAnswer) {
            // Display error message if question or answer is empty
            errorMessage.classList.remove("hide");
        } else {
            if (editBool) {
            // If editing an existing flashcard, remove the original flashcard from the array
            flashcards = flashcards.filter(flashcard => flashcard.id !== originalId);
            }
            let id = Date.now();
            // Add the new flashcard to the array
            flashcards.push({ id, question: tempQuestion, answer: tempAnswer });
            // Save the flashcards array to local storage
            localStorage.setItem('flashcards', JSON.stringify(flashcards));
            container.classList.remove("hide");
            errorMessage.classList.add("hide");
            viewlist();
            question.value = "";
            answer.value = "";
            editBool = false;
            addQuestionCard.classList.add("hide"); // This line hides the modal after the flashcard is added
        }
        });

        // Function to display the flashcard list
        function viewlist() {
        const listCard = document.querySelector(".card-list-container");
        listCard.innerHTML = '';
        flashcards = JSON.parse(localStorage.getItem('flashcards')) || [];
        flashcards.forEach(flashcard => {
            const div = document.createElement("div");
            div.classList.add("card");
            div.innerHTML = `
            <p class="question-div">${flashcard.question}</p>
            <p class="answer-div hide">${flashcard.answer}</p>
            <a href="#" class="show-hide-btn">Show/Hide</a>
            <div class="buttons-con">
                <button class="edit"><i class="fa-solid fa-pen-to-square"></i></button>
                <button class="delete"><i class="fa-solid fa-trash-can"></i></button>
            </div>
            `;
            div.setAttribute('data-id', flashcard.id);
            const displayAnswer = div.querySelector(".answer-div");
            const showHideBtn = div.querySelector(".show-hide-btn");
            const editButton = div.querySelector(".edit");
            const deleteButton = div.querySelector(".delete");

            showHideBtn.addEventListener("click", () => {
            // Toggle the visibility of the answer
            displayAnswer.classList.toggle("hide");
            });

            editButton.addEventListener("click", () => {
            // Enable editing mode and show the add question card
            editBool = true;
            modifyElement(editButton, true);
            addQuestionCard.classList.remove("hide");
            });

            deleteButton.addEventListener("click", () => {
            // Delete the flashcard
            modifyElement(deleteButton);
            });

            listCard.appendChild(div);
        });
        }

        // Function to modify a flashcard element
        const modifyElement = (element, edit = false) => {
        const parentDiv = element.parentElement.parentElement;
        const id = Number(parentDiv.getAttribute('data-id'));
        const parentQuestion = parentDiv.querySelector(".question-div").innerText;
        if (edit) {
            const parentAns = parentDiv.querySelector(".answer-div").innerText;
            answer.value = parentAns;
            question.value = parentQuestion;
            originalId = id;
            disableButtons(true);
        } else {
            // Remove the flashcard from the array and update local storage
            flashcards = flashcards.filter(flashcard => flashcard.id !== id);
            localStorage.setItem('flashcards', JSON.stringify(flashcards));
        }
        parentDiv.remove();
        };

        // Function to disable edit buttons
        const disableButtons = (value) => {
        const editButtons = document.getElementsByClassName("edit");
        Array.from(editButtons).forEach((element) => {
            element.disabled = value;
        });
        };

        // Event listener to display the flashcard list when the DOM is loaded
        document.addEventListener("DOMContentLoaded", viewlist);
    </script>
  </body>
</html>




)=====";

const char js_script[] =
R"=====(
  <html>
    <body>
      <h1>Test Output</h1>
      <form>
        <input type='checkbox' id='switch' name='switch'>
        <label for='switch'>Switch</label>
      </form>
      <script>
        const switchButton = document.getElementById('switch');
        switchButton.addEventListener('change', () => {
          if (switchButton.checked) {
            sendSwitchState('on');
          } else {
            sendSwitchState('off');
          }
        });
        
        function sendSwitchState(state) {
          const xhr = new XMLHttpRequest();
          xhr.open('GET', '/api/testoutput/' + state, true);
          xhr.send();
        }
      </script>
    </body>
  </html>
)=====";

const char button_js_script[] =
R"=====(
    <html>
      <body>
        <h1>Button Test</h1>
        <button id="b1" onclick="sendButtonState('b1')">Button 1</button>
        <button id="b2" onclick="sendButtonState('b2')">Button 2</button>
        <button id="b3" onclick="sendButtonState('b3')">Button 3</button>
        <button id="b4" onclick="sendButtonState('b4')">Button 4</button>
        <script>
          // Function to send a GET request to the ESP with the button state
          function sendButtonState(state) {
            const xhr = new XMLHttpRequest();
            xhr.open('GET', '/api/buttontest/' + state, true);
            xhr.send();
          }
        </script>
      </body>
    </html>
)=====";