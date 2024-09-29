//button tests
const char button_js_script[] =
R"=====(
    <html>
    <head>
        <title>Steuerung mit WASD</title>
        <link rel="preconnect" href="https://fonts.googleapis.com">
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
        <link href="https://fonts.googleapis.com/css2?family=Fredoka:wght@300..700&display=swap" rel="stylesheet">
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
