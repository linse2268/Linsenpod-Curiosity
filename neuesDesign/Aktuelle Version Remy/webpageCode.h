//imported codes for the html files


//driving endpoint html code
const char drivepanel[] =
R"=====(  
    
<html>
  <head>
    <title>Steuerung</title>
    <link rel="preconnect" href="https://fonts.googleapis.com" />
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
    <link
      href="https://fonts.googleapis.com/css2?family=Fredoka:wght@300..700&display=swap"
      rel="stylesheet"
    />

    <link
      rel="icon"
      href="https://squidpod.github.io/images/pics/final_light.png"
    />

    <style>
      :root {
        --backgroundcolor: rgb(53, 53, 53);
        --fontcolor: rgb(185, 185, 185);
        --bodybackgroundcolor: rgb(29, 29, 29);
        --linsenPodcolor: rgb(150, 150, 150);
        --backgroundcolorHover: rgb(66, 66, 66);
      }
      * {
        font-family: "Fredoka", sans-serif;
        color: var(--fontcolor);
        margin: 0;
        padding: 0;
        user-select: none;
      }
      body {
        width: 98vw;
        height: 98vh;
        padding: 1vw;

        display: grid;
        grid-template-columns: 1fr 1fr 1fr 1fr 1fr 1fr;
        grid-template-rows: 1fr 1fr 1fr 1fr 1fr 1fr 1fr;
        gap: 1vw;
        background-color: var(--bodybackgroundcolor);
        overflow: hidden;
      }
      button {
        background-color: var(--backgroundcolor);
        border-radius: 1vw;
        border: none;
        font-size: 2em;
        transition: 200ms;
      }
      button:hover{
        background-color: var(--backgroundcolorHover);
      }
      div {
        background-color: var(--backgroundcolor);
        border-radius: 1vw;
        border: none;
        display: flex;
        justify-content: center;
        align-items: center;
        font-size: 2em;
        transition: 200ms;
      }
      img {
        display: block;
        user-select: none;
        margin: auto;
        background-color: var(--backgroundcolor);
        width: 100%;
        height: 100%;
        grid-row: 1 / 6;
        grid-column: 1 / 5;
        border-radius: 1vw;
      }
      #fakten {
        grid-column: 5/7;
        grid-row: 1/7;
        display: flex;
        flex-direction: column;
        justify-content: start;
        flex-shrink: 0;
        padding-top: 2vw;
      }
      
      ul{
        font-size: 0.4em;
      }
      #banner {
        padding: 0;
        margin: 0;
        grid-column: 5 / 7;
        display: flex;
        justify-content: center;
        align-items: center;
      }

      #linsenpodBanner {
        font-size: 1.5vw;
        font-weight: 300;
        color: var(--linsenPodcolor);
        padding-right: 0.5vw;
      }
      #curiosityBanner {
        font-size: 3vw;
      }

      #big {
        border-radius: 0;
        width: 100vw;
        height: 100vh;
        position: absolute;
        top: 0;
        left: 0;
        display: none;
        justify-content: center;
        align-items: center;
        background-color: rgba(0, 0, 0, 0.6);
        backdrop-filter: blur(10px);
      }
      @keyframes backgroundBlur {
        0% {
          backdrop-filter: blur(0px);
          display: flex;
          background-color: rgba(0, 0, 0, 0);
        }
        100% {
          backdrop-filter: blur(10px);
          display: flex;
        }
      }
      @keyframes backgroundBlurReverse {
        0% {
          backdrop-filter: blur(10px);
        }
        100% {
          backdrop-filter: blur(0px);
          background-color: rgba(0, 0, 0, 0);
        }
      }
      #lilBig {
        width: 60vw;
        height: 70vh;
        position: relative;
        display: flex;
        justify-content: space-between;
        align-items: start;
        padding: 1vw;
        animation-name: menuOpenAnimation;
        animation-duration: 150ms;
        animation-timing-function: linear;
      }
      @keyframes menuOpenAnimation {
        0% {
          opacity: 0;
          scale: 0.7;
        }
        100% {
          opacity: 1;
          scale: 1;
        }
      }
      @keyframes menuCloseAnimation {
        0% {
          opacity: 1;
          scale: 1;
        }
        100% {
          opacity: 0;
          scale: 0.7;
        }
      }
      #lilBigButton {
        font-size: 2vw;
        font-weight: bolder;
        width: 3vw;
        height: 3vw;
        background-color: var(--backgroundcolorHover);
        display: flex;
        justify-content: center;
        align-items: center;
      }

      #logoinfo {
        width: 5vw;
        height: 5vw;
        margin: 1vw;
      }

      #lilBigHeader {
        width: 100%;
        display: flex;
        justify-content: space-between;
      }
      #lilbigcontent {
        width: 100%;
        display: flex;
        flex-direction: column;
      }
      .menuContent {
        width: 90%;
        display: flex;
        justify-content: space-between;
        border: 3px solid var(--backgroundcolorHover);
        padding: 0.5vw;
        margin-bottom: 0.5vw;
      }
      #themeLabel {
        font-size: 1.5rem;
      }
      #info {
        width: 100%;
        font-size: 1rem;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        position: absolute;
        bottom: 1vw;
      }
      select {
        background-color: var(--backgroundcolor);
        border: 2px solid var(--backgroundcolorHover);
        border-radius: 0.5vw;
        font-size: 1.5rem;
      }
      .buttons {
        transition: 200ms;
      }
      .buttons:hover {
        background-color: var(--backgroundcolorHover);
      }
    </style>
  </head>
  <body>
    <div id="fakten"><h4>Fakten:</h1><div><ul><li>maximale Geschwindigkeit: 5km/h</li><li>Zugkraft: 5 Newton</li><li>Gewicht: 400g</li><li>Abmessungen: 20*30*40cm</li></ul></div></div>
    <div>2</div>
    <div>3</div>


    <img id="img" src="http://192.168.18.168:8080/video" />
    <button class="button" id="w" onclick="sendButtonState('honk')">
      HUPE
    </button>
    <button class="button" id="a" onclick="sendButtonState('a')">
      Button 2
    </button>
    <button class="button" id="s" onclick="sendButtonState('s')">
      Button 3
    </button>
    <button class="button" id="d" onclick="sendButtonState('d')">
      Button 4
    </button>
    <div id="counterDisplay">Speed: <span id="counter">4</span>/7</div>
    <div id="testFürWASD">1</div>
    <!--Menu(z.B. Dark/Lightmode)-Menu(z.B. Dark/Lightmode)-Menu(z.B. Dark/Lightmode)-Menu(z.B. Dark/Lightmode)--->
    <div id="big">
      <div id="lilBig">
        <div id="lilbigcontent">
          <div id="lilBigHeader">
            <div>
              <img
                id="logoinfo"
                src="https://squidpod.github.io/images/pics/final_light.png"
              />
              <h5 id="linsenpodBanner">LinsenPod</h5>
              <h3 id="curiosityBanner"><b>Curiosity</b></h3>
            </div>
            <button class="button" id="lilBigButton" onclick="hideMenu()">
              OK
            </button>
          </div>
          <div class="menuContent">
            <label for="options" id="themeLabel">Theme:</label>
            <select id="options" name="options">
              <option value="true">Dark</option>
              <option value="false">Light</option>
            </select>
          </div>
          <div id="info">
            <a
              href="https://github.com/linse2268/Linsenpod-Curiosity/"
              target="_blank"
              ><h3 id="githublink">Unser Github Repository</h3></a
            >
            <p id="copyright">
              von Rémy Göttlich und Linus Bös im Rahmen des
              Informatik-Unterrichts bei Herrn Hagedorn 2024/2025
            </p>
          </div>
        </div>
      </div>
    </div>
    <!--Menu(z.B. Dark/Lightmode)-Menu(z.B. Dark/Lightmode)-Menu(z.B. Dark/Lightmode)-Menu(z.B. Dark/Lightmode)--->
    <button class="button" id="banner" onclick="openMenu()">
      <h5 id="linsenpodBanner">LinsenPod</h5>
      <h3 id="curiosityBanner"><b>Curiosity</b></h3>
      <button id="menuOpenButton"></button>
    </button>

    <script>
      function sendButtonState(state) {
        const xhr = new XMLHttpRequest();
        xhr.open("GET", "/drivepanel/" + state, true);
        xhr.send();
      }

      function updateMovement(event) {
        if (event.type === "keydown") {
          sendButtonState(event.key);
        } else if (event.type === "keyup") {
          sendButtonState(event.key + "_release");
        }
      }

      const keysPressed = {
        w: false,
        a: false,
        s: false,
        d: false,
        p: false,
        up: false,
        down: false,
        left: false,
        right: false,
      };

      document.addEventListener("keydown", function (event) {
        switch (event.key) {
          case "w":
            if (!keysPressed.w) {
              keysPressed.w = true;
              updateMovement(event);
            }
            break;
          case "a":
            if (!keysPressed.a) {
              keysPressed.a = true;
              updateMovement(event);
            }
            break;
          case "s":
            if (!keysPressed.s) {
              keysPressed.s = true;
              updateMovement(event);
            }
            break;
          case "d":
            if (!keysPressed.d) {
              keysPressed.d = true;
              updateMovement(event);
            }
            break;
          case "p":
            if (!keysPressed.p) {
              keysPressed.p = true;
              updateMovement(event);
            }
            break;
          case "ArrowUp":
            if (!keysPressed.up) {
              keysPressed.up = true;
              updateMovement(event);
            }
            break;
          case "ArrowDown":
            if (!keysPressed.down) {
              keysPressed.down = true;
              updateMovement(event);
            }
            break;
          case "ArrowLeft": // Handle left arrow key
            if (!keysPressed.left) {
              keysPressed.left = true;
              updateMovement(event);
            }
            break;
          case "ArrowRight": // Handle right arrow key
            if (!keysPressed.right) {
              keysPressed.right = true;
              updateMovement(event);
            }
            break;
        }
      });

      document.addEventListener("keyup", function (event) {
        switch (event.key) {
          case "w":
            keysPressed.w = false;
            updateMovement(event);
            break;
          case "a":
            keysPressed.a = false;
            updateMovement(event);
            break;
          case "s":
            keysPressed.s = false;
            updateMovement(event);
            break;
          case "d":
            keysPressed.d = false;
            updateMovement(event);
            break;
          case "p":
            keysPressed.p = false;
            updateMovement(event);
            break;
          case "ArrowUp":
            keysPressed.up = false;
            updateMovement(event);
            break;
          case "ArrowDown":
            keysPressed.down = false;
            updateMovement(event);
            break;
          case "ArrowLeft": // Handle left arrow key release
            keysPressed.left = false;
            updateMovement(event);
            updateCounter();
            break;
          case "ArrowRight": // Handle right arrow key release
            keysPressed.right = false;
            updateMovement(event);
            updateCounter();
            break;
        }
      });

      // Function to update the counter (same as your original code)
      function updateCounter() {
        const xhr = new XMLHttpRequest();
        xhr.open("GET", "/var", true); // Anfrage an den /var Endpunkt
        xhr.onload = function () {
          if (xhr.status == 200) {
            var response = JSON.parse(xhr.responseText); // JSON verarbeiten
            document.getElementById("counter").innerText = response.wert; // HTML aktualisieren
          }
        };
        xhr.send(); // Anfrage absenden
      }

      const menu = document.getElementById("big");
      const menuContent = document.getElementById("lilBig");
      const themeSelect = document.getElementById("options");
      const buttons = document.getElementsByClassName("");
      //-
      function hideMenu() {
        const darkOrLight = themeSelect.value;
        buttons.style = "tranistion: 0;";
        lightDark(darkOrLight);
        menu.style =
          "display:flex; animation: backgroundBlurReverse 150ms linear;";
        menuContent.style = "animation-name: menuCloseAnimation";
        setTimeout(function () {
          menu.style = "display: none;";
          buttons.style = "tranistion: 200ms;";
        }, 150);
      }

      function openMenu() {
        menu.style = "display: flex; animation: backgroundBlur 100ms linear;";
        menuContent.style = "animation-name: menuOpenAnimation;";
      }

      function lightDark(dark) {
        if (dark == "true") {
          document.documentElement.style.setProperty(
            "--backgroundcolor",
            "rgb(53, 53, 53)"
          );
          document.documentElement.style.setProperty(
            "--fontcolor",
            "rgb(185, 185, 185)"
          );
          document.documentElement.style.setProperty(
            "--bodybackgroundcolor",
            "rgb(29, 29, 29)"
          );
          document.documentElement.style.setProperty(
            "--linsenPodcolor",
            "rgb(150, 150, 150)"
          );
          document.documentElement.style.setProperty(
            "--backgroundcolorHover",
            "rgb(66, 66, 66)"
          );
        } else if (dark == "false") {
          document.documentElement.style.setProperty(
            "--backgroundcolor",
            "rgb(202, 202, 202)"
          );
          document.documentElement.style.setProperty(
            "--fontcolor",
            "rgb(29, 29, 29)"
          );
          document.documentElement.style.setProperty(
            "--bodybackgroundcolor",
            "rgb(185, 185, 185)"
          );
          document.documentElement.style.setProperty(
            "--linsenPodcolor",
            "rgba(29, 29, 29, 0.75)"
          );
          document.documentElement.style.setProperty(
            "--backgroundcolorHover",
            "rgb(219, 219, 219)"
          );
        }
      }
    </script>
  </body>
</html>

)=====";

//normal homepage
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
        <a href="/drivepanel"><button id="steeringSite">Probier mich aus!</button></a>


        <div id="info">
            
                <h1>Unsere Idee:</h1>
                <div id="idee">
                    <p>Curiosity ist ein Auto, das über eine Website gesteuert wird, auf der ein Livebild von einer Handykamera zu sehen ist, die sich auf dem Auto befindet. Die Website läuft auf einem ESP 8266 Mikrokontroller, der über WLAN mit einem Browser verbunden werden kann. So kann man das Auto überall dort fahren, wo das Auto dasselbe WLAN wie der Browser hat. Der Fahrer kann jedoch bequem an einem Platz bleiben.</p>

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
