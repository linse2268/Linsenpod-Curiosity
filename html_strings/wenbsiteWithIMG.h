<html>
    <head>
        <title>Steuerung</title>
        <style>
            body{
                margin: 0;
                padding: 0;
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
        </style>
    </head>
      <body>
        <!--ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-->
        <img id="img" src="http://192.168.2.106:8080/video">
        <button id="b1" onclick="sendButtonState('b1')">Button 1</button>
        <button id="b2" onclick="sendButtonState('b2')">Button 2</button>
        <button id="b3" onclick="sendButtonState('b3')">Button 3</button>
        <button id="b4" onclick="sendButtonState('b4')">Button 4</button>
        <!--ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-ELEMENTE-->
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
