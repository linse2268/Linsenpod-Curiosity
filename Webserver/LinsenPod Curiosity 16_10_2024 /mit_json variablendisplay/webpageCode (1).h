//button tests
const char button_js_script[] =
R"=====(
    <html>
    <head>
        <title>Steuerung mit WASD</title>
        <link rel="preconnect" href="https://fonts.googleapis.com">
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
        <link href="https://fonts.googleapis.com/css2?family=Fredoka:wght@300..700&display=swap" rel="stylesheet">

        <link rel="icon" href="https://squidpod.github.io/images/pics/final_light.png">

        <style>
          *{
            font-family: "Fredoka", sans-serif;
            color: rgb(185, 185, 185);
            margin: 0;
            padding: 0;
            user-select: none;
          }
            body{
                width: 98vw;
                height: calc(100vh - 2vw);
                padding: 1vw;

                display: grid;
                grid-template-columns: 1fr 1fr 1fr 1fr 1fr 1fr;
                grid-template-rows: 1fr 1fr 1fr 1fr 1fr 1fr 1fr;
                gap: 1vw;
                background-color: rgb(29, 29, 29);
            }
            button{
                background-color: rgb(53, 53, 53);
                border-radius: 1vw;
                border: none;
                font-size: 2em;
            }
            div{
                background-color: rgb(53, 53, 53);
                border-radius: 1vw;
                border: none;
                display: flex;
                justify-content: center;
                align-items: center;
                font-size: 2em;
            }
            img{
                display: block; 
                user-select: none; 
                margin: auto; 
                background-color: hsl(0, 0%, 19%); 
                width: 100%; 
                height: 100%;
                grid-row: 1 / 6;
                grid-column: 1 / 5;                
                border-radius: 1vw;
            }
            #banner{
              padding: 0;
              margin: 0;
              grid-column: 5 / 7;
              display: flex;
              
            }
            h5{
              font-size: 1.5vw;
              font-weight: 300;
              color: rgb(150, 150, 150);
              padding-right: 0.5vw;
            }
            h3{
              font-size: 3vw;
            }
      
        </style>
    </head>
      <body>
        <!--ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-->
        <img id="img" src="http://192.168.2.106:8080/video">
        <button id="w" onclick="sendButtonState('w')">Button 1</button>
        <button id="a" onclick="sendButtonState('a')">Button 2</button>
        <button id="s" onclick="sendButtonState('s')">Button 3</button>
        <button id="d" onclick="sendButtonState('d')">Button 4</button>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div id="testFürWASD">1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div>1</div>
        <div id="banner"><h5>LinsenPod</h5> <h3><b>Curiosity</b></h3></div>
        <!--ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-->
        <script>
            // Function to send a GET request to the ESP with the button state
            // Function to send a GET request to the ESP with the button state
            function sendButtonState(state) {
              const xhr = new XMLHttpRequest();
              xhr.open('GET', '/api/buttontest/' + state, true);
              xhr.send();
            }

            // Funktion zum Aktualisieren der Bewegung
            function updateMovement(event) {
              if (event.type === 'keydown') {
                // Send request to ESP when a key is pressed
                sendButtonState(event.key);
              } else if (event.type === 'keyup') {
                // Send request to ESP when a key is released
                sendButtonState(event.key + '_release');
              }
            }

            const keysPressed = {
              w: false,
              a: false,
              s: false,
              d: false
            };

            document.addEventListener("keydown", function(event) {
              switch(event.key) {
                case 'w':
                  if (!keysPressed.w) {
                    keysPressed.w = true;
                    updateMovement(event);
                  }
                  break;
                case 'a':
                  if (!keysPressed.a) {
                    keysPressed.a = true;
                    updateMovement(event);
                  }
                  break;
                case 's':
                  if (!keysPressed.s) {
                    keysPressed.s = true;
                    updateMovement(event);
                  }
                  break;
                case 'd':
                  if (!keysPressed.d) {
                    keysPressed.d = true;
                    updateMovement(event);
                  }
                  break;
              }
            });

            document.addEventListener("keyup", function(event) {
              switch(event.key) {
                case 'w':
                  keysPressed.w = false;
                  updateMovement(event);
                  break;
                case 'a':
                  keysPressed.a = false;
                  updateMovement(event);
                  break;
                case 's':
                  keysPressed.s = false;
                  updateMovement(event);
                  break;
                case 'd':
                  keysPressed.d = false;
                  updateMovement(event);
                  break;
              }
            });
            </script>
      </body>
</html>
)=====";

const char homepagecode[] =
R"=====(
  <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="preconnect" href="https://fonts.googleapis.com">
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
        <link href="https://fonts.googleapis.com/css2?family=Fredoka:wght@300..700&display=swap" rel="stylesheet">
        <title>linsenpod curiosity home</title>

        <link rel="icon" href="https://squidpod.github.io/images/pics/final_light.png">
        
        <style>
            :root{
                --backgroundcolor: rgb(53, 53, 53);
            }
            *{
                font-family: "Fredoka", sans-serif;
                color: rgb(185, 185, 185);
                
                
            }

            body{
                background-color: rgb(29, 29, 29);
                padding: 2vw;
                display: flex;
                flex-direction: column;
                align-items: center;
            }
            h1{
                font-size: 3.5vw;
            }

            button{
                background-color: var(--backgroundcolor);
                border: none;
                font-size: 2em;
                border-radius: 1vw;
            }
            ul{
                font-size: 2vw;
            }
            p{
                font-size: 1.5vw;
            }

            #banner{
                display: flex;
                justify-content: center;
                align-items: center;
            }

            #linsenpod{
                font-size: 4vw;
                font-weight: 400;
                color: rgb(150, 150, 150);
            }

            #Curiosity{
                font-size: 7vw;
            }
          
            #steeringSite{
                font-weight: bolder;
                font-size: 3.5vw;
                padding: 2vw 4vw;
                animation: Shadow 3s ease-in-out infinite;
                
            }

            @keyframes Shadow{
                0%{box-shadow: 0;}
                50%{box-shadow:  0 0 3vw rgba(0, 0, 0, 0.66); transform: scale(1.02); background-color: rgb(66, 66, 66);}
                100%{box-shadow: 0;}
            }

            #info{
                margin-top: 5vw;
                width: 80vw;
                background-color: var(--backgroundcolor);
                border-radius: 1vw;
                padding: 2vw 3vw;
                padding-bottom: 0;
                display: flex;
                flex-direction: column;
                align-items: center;
            }
            
            #idee{
                margin: 0;
                padding: 0;
            }
            #githublink{
                transition: 300ms;
            }
            #githublink:hover{
                transform: scale(1.1);
            }
        </style>
    </head>
    <body>
        <div id="banner">
            <h3 id="linsenpod">LinsenPod</h3><h1 id="Curiosity">Curiosity</h1>
        </div>
        <a href="/api/buttontest"><button id="steeringSite">Probier mich aus!</button></a>


        <div id="info">
            
                <h1>Unsere Idee:</h1>
                <div id="idee">
                    <p>Curiosity ist ein Auto, das über eine Website gesteuert wird, auf der ein Livebild von einer Handykamera zu sehen ist, das sich auf dem Auto befindet. Die Website läuft auf einem ESP 8266 Mikrokontroller, der über WLAN mit einem Browser verbunden werden kann. So kann man das Auto überall dort fahren, wo das Auto dasselbe WLAN wie der Browser hat. Der Fahrer kann jedoch bequem an einem Platz bleiben.</p>

                    <p>Weitere Features, wie eine Hinderniserkennung durch einen Ultraschallsensor, der kontinuierlich den Abstand zu Objekten vor sich misst, machen das Fahrerlebnis komfortabler. Außerdem verfügt das Auto über einen Lautsprecher und Lichter, um im Weg stehende Personen auf sich aufmerksam zu machen.</p>
                </div>
            
            
                <!--
                <h1>Materialien:</h1>
                <ul>
                    <li>ESP 8266</li>
                    <li>Arudino Uno</li>
                    <li>Lego Technic</li>
                    <li>Handy</li>
                    
                    <li></li>
                    <li></li>
                    <li></li>
                </ul>
                -->

                <h1>Tech-Stack:</h1>
                <ul>
                    <li>C++</li>
                    <li>Html</li>
                    <li>CSS</li>
                    <li>JavaScript</li>
                    <li>Notion</li>
                    <li>Github</li>
                    <li>Arduino IDE</li>
                    <li>VS Code</li>
                </ul>
                <a href="https://github.com/linse2268/Linsenpod-Curiosity/" target="_blank"><h3 id="githublink">Unser Github Repository</h3></a>
                <p>von Rémy Göttlich und Linus Bös im Rahmen des Informatik Unterrichtes bei Herrn Hagedorn 2024/2025</p>
        </div>
    </body>
    </html>
)=====";

const char imagedisplay[] =
R"=====(
  <!DOCTYPE html>
    <html lang="en">
      <head>
          <meta charset="UTF-8">
          <meta name="viewport" content="width=device-width, initial-scale=1.0">
          <title>Document</title>
          <link rel="icon" href="https://squidpod.github.io/images/pics/final_light.png">
      </head>
      <body>
          <img src="https://squidpod.github.io/images/pics/final_dark.png" >
      </body>
    </html>
)=====";