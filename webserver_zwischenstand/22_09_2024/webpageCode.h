const char webpagecode[] = 
R"=====(
  <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        button{
            border: none;
            border-radius: 1vw;
            width: 30vw;
            height: 50vh;
            font-size: 3vw;
        }
        #blue{
            background-color: red;
        }
        #red{
            background-color: blue;
            
        }
    </style>
</head>
<body>
    <button id="red">red button</button>
    <button id="blue">blue button</button>
</body>
</html>
)=====";

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

const char dinogame[] =
R"=====(
  <!DOCTYPE html>
<html lang="en" >
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TheDinoGameTest</title>

<!--STYLE-STYLE-STYLE-STYLE-STYLE-STYLE-STYLE-STYLE-STYLE-STYLE-STYLE-STYLE-STYLE-STYLE-STYLE--->
    <style>
        *{
    margin: 0;
    padding: 0;
    font-family: Helvetica, sans-serif;
    user-select: none;
}

body{ 
    background-color: rgb(66, 66, 66);
    height: 100vh;
    width: 100vw;
    display: flex;
    justify-content: center;
    align-items: center;
    z-index: 5;
}

#content{
    display: flex;
    flex-direction: column;
    align-items: center;
}

h1{
    position: relative;
    top: -60px;
    font-size: 7em;
    font-weight: 800;
    color: rgba(255, 255, 255, 0.24);
    
}

.points{
    display: flex;
    justify-content: space-between;
    width: 850px;
}

h5{
    font-size: 2em;
    font-weight: 800;
    color: rgba(255, 255, 255, 0.24);
    
}

#game{
    height: 300px;
    width: 900px;
    
    border-radius: 10px;
    box-shadow: inset 0 0 20px black;
    background-color: rgb(71, 71, 71);
    z-index: 3;
    overflow: hidden;
}

#character{
    width: 30px;
    height: 80px;
    background-color: rgb(93, 223, 104);
    border-radius: 10px;
    position: relative;
    top: 217px;
    left: 10px;
    z-index: 2;
}

#block{
    width: 40px;
    height: 40px;
    border-radius: 4px;
    background-color: rgb(255, 166, 0);
    position: relative;
    top: 178px;
    left: 900px;
    z-index: 1;
    display: none;
    animation:block linear infinite;
    animation-duration: 1.5s;
}

@keyframes block{
    to{left: -90px;}
}

#restart{

    width: 200px;
    height: 80px;
    border: none;
    border-radius: 20px;
    background-color:  rgb(71, 71, 71);
    box-shadow: inset 0 0 15px black;
    position: relative;
    top: 50px;
    color: rgba(255, 255, 255, 0.24);
    font-size: 3em;
    font-weight: 700;
}


@media (max-width:900px){

    h1{
        font-size: 2em;
        top: -40px;
    }

    #restart{

        width: 90px;
        height: 40px;
        top: 30px;
        font-size: 1em;
        box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.603);
    }

    .points{
        width: 370px;
    }
    h5{
        font-size: 1.1em;
        font-weight: 800;
        color: rgba(255, 255, 255, 0.24);
    }
    #game{
        height: 150px;
        width: 400px;
        overflow: hidden;
    }

    #character{
        width: 15px;
        height: 40px;
        border-radius: 5px;
        position: relative;
        top: 105px;
        left: 8px;
    }

    @keyframes jump{
        0%{top: 105px;}
        30%{top: 75px;}
        70%{top: 75px;}
        100%{top: 105px;}
    }

    #block{
        width: 20px;
        height: 20px;
        border-radius: 2px;
        position: relative;
        top: 90px;
        left: 100px;
    }

    @keyframes block{
        0%{left: 390px;}
        100%{left: -10px;}
    }
}

@media (max-width:500px){

    h1{
        font-size: 2em;
        top: -30px;
    }

    #restart{

        width: 90px;
        height: 40px;
        font-size: 1em;
        top: 20px;
        box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.603);
    }

    .points{
        width: 280px;
    }

    h5{
        font-size: 0.8em;
        font-weight: 800;
        color: rgba(255, 255, 255, 0.24);
    }
    #game{
        height: 150px;
        width: 300px;
        overflow: hidden;
    }

    #character{
        width: 15px;
        height: 40px;
        border-radius: 5px;
        position: relative;
        top: 105px;
        left: 8px;
    }

    @keyframes jump{
        0%{top: 105px;}
        30%{top: 75px;}
        70%{top: 75px;}
        100%{top: 105px;}
    }

    #block{
        width: 20px;
        height: 20px;
        border-radius: 2px;
        position: relative;
        top: 90px;
        left: 100px;
    }

    @keyframes block{
        0%{left: 390px;}
        100%{left: -10px;}
    }
}
    </style>

<!--STYLEEND-STYLEEND-STYLEEND-STYLEEND-STYLEEND-STYLEEND-STYLEEND-STYLEEND-STYLEEND-STYLEEND-STYLEEND-STYLEEND-STYLEEND--->
</head>
<body id="body">
    <div id="content">

        <h1 id="text">Let's Play!</h1>
        <div class="points">
            <h5 id="highscore">HScr 00000</h5>
            <h5 id="score">Scr 00000</h5>
            <h5 id="round">Rnd 00</h5>
        </div>
        <div id="game">

            <div id="character"></div>
            <div id="block"></div>
            
        </div>
        <button id="restart" onclick="restart()">Start</button>

    </div>
<!--SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT-SCRIPT---> 
    <script>
var character = document.getElementById('character');       //player
var block = document.getElementById('block');               //enemy
var text = document.getElementById('text');
var body = document.getElementById('body');
var score = document.getElementById('score');               //score
var highscoreText = document.getElementById('highscore');
var roundText = document.getElementById('round');
var roundValue = 0;
var highscoreValue = 0;
var viewportWidth = parseInt(window.innerWidth);            //measures the width of the users display
var running = false;                                                     
var jumpHeight = 162; // Default jump height                //jumpheight (later set by viewportWidth)
var jumpDuration = 500;                                     
var current
var jumping = false;                        

block.style.animation = "none";
block.style.display = "none";


// Adjust jump height based on viewport width
setInterval(function(){
    if (viewportWidth <= 900) {
        jumpHeight = 30;          //small view!!!!!!!!!!!!!!!!!!!!
        normalHeight = 105;
    } else {
        jumpHeight = 100;         //normal desktop view!!!!!!!!!!!!!!!!!!!!!!
        normalHeight = 217;
    }
},10)


body.addEventListener('click', jumpactive); 


function jumpactive(){       // checks, if game is running && not already jumping 
    if(running && !jumping ){
        jump();
    }
}

function jump() {
        jumping = true;   //declares that character is jumping --> cannot jump again until jump is finished
        const startTime = performance.now();

        function animateJump(currentTime) {
            const elapsedTime = currentTime - startTime;
            const progress = elapsedTime / jumpDuration;

            if (progress < 1) {
                const jumpProgress = Math.sin(progress * Math.PI); // Apply a sine function for a more natural jump curve
                const heightOffset = normalHeight - (jumpProgress * jumpHeight);

                character.style.top = heightOffset + 'px';

                requestAnimationFrame(animateJump);
            } else {
                character.style.top = normalHeight + 'px'; // Reset position
                jumping = false;  //declares that is not jumping --> player can jump again
            }
            
        }
        requestAnimationFrame(animateJump); 
}

var checkdead = setInterval(function() {
    var characterTop = parseInt(window.getComputedStyle(character).getPropertyValue("top"));
    var blockLeft = parseInt(window.getComputedStyle(block).getPropertyValue("left"));

    if (viewportWidth <= 900) {
        if (blockLeft < 20 && blockLeft > 0 && characterTop >= 90) {
            contact();
        }
    } else {
        if (blockLeft < 40 && blockLeft > 0 && characterTop >= 175) {
            contact();
        }
    }
}, 10)

function contact(){
    block.style.animation = "none";
    block.style.display = "none";
    
    newHighscore();
    running = false;
    character.style.top = normalHeight + 'px'; // Reset position
    text.innerText = "You Lose";
    setTimeout(function() {
        text.innerText = "Let's Play!";
    }, 3000)
}

function newHighscore(){
    if(highscoreValue < time){
        console.log("new highscore '" + time + "' in round " + roundValue);
        highscoreText.innerText = "HScr " + time;
        highscoreValue = time;
    }
}


function restart() {            //used for Start and restart
    runningFunction();
    time = 0;
    roundValue++;
    if(roundValue < 10){
        roundValue = "0" + roundValue;
    }
    roundText.innerText = "Rnd " + roundValue; 
    score.innerText = "Scr 00000";
    jumping = true;
    running = true;
    setTimeout(function(){
        jumping = false;
    },1)

}

function runningFunction() {
    block.style.animation = "block linear infinite";
    block.style.animationDuration = "1.5s"
    block.style.display = "block";
    
}
 


var time = 0;
setInterval(function() {
    if (running) {

        time++;
        if(time < 10){
            time = "0000" + time;
        }
        else if(time < 100){
            time = "000" + time;
        }
        else if(time < 1000){
            time = "00" + time;
        }
        else if(time < 10000){
            time = "0" + time;
        }
        score.innerText = "Scr " + time;
    }
}, 100)
    </script>

<!--SCRIPTEND-SCRIPTEND-SCRIPTEND-SCRIPTEND-SCRIPTEND-SCRIPTEND-SCRIPTEND-SCRIPTEND-SCRIPTEND-SCRIPTEND-SCRIPTEND-SCRIPTEND---> 

</body>

</html>
)=====";




