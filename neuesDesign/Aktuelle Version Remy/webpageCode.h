//imported codes for the html files


//driving endpoint html code
const char drivepanel[] =
R"=====(  
    <!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
    <link rel="preconnect" href="https://fonts.googleapis.com" />
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
    <link
      href="https://fonts.googleapis.com/css2?family=Fredoka:wght@300..700&display=swap"
      rel="stylesheet"
    />
    <title>Drivepanel</title>
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
        -webkit-touch-callout: none;
        -webkit-user-select: none;
      }

      body {
        width: 100dvw;
        height: 100dvh;
        overflow: hidden;
        background-color: var(--bodybackgroundcolor);
      }
      #bodyContentAskDivice {
        width: 98dvw;
        height: 96dvh;
        padding: 1dvw;
        display: flex;
        justify-content: center;
        align-items: center;
        background-color: var(--bodybackgroundcolor);
      }
      .askDiviceButton {
        background-color: var(--backgroundcolor);
        border-radius: 1dvw;
        border: 2px solid var(--fontcolor);
        font-size: 3vw;
        transition: 300ms;
        padding: 2dvw 3dvw;
        margin: 1vw;
      }
      .askDiviceButton:hover {
        background-color: var(--backgroundcolorHover);
      }
      .requeststBeforSteeringSite {
        padding: 5dvw;
        background-color: var(--backgroundcolor);
        border-radius: 1dvw;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        box-shadow: 0 0 6vw black;
      }
      #askDiviceH1 {
        font-size: 4dvw;
        padding: 3dvw;
      }

      #desktopSteeringSite {
        width: 98dvw;
        height: 96dvh;
        padding: 1dvw;

        display: none;
        grid-template-columns: 1fr 1fr 1fr 1fr 1fr 1fr;
        grid-template-rows: 1fr 1fr 1fr 1fr 1fr 1fr 1fr;
        gap: 1dvw;
        background-color: var(--bodybackgroundcolor);
        overflow: hidden;
        transition: 200ms;
      }

      
      .desktopSteeringButton {
        background-color: var(--backgroundcolor);
        border-radius: 1dvw;
        border: none;
        font-size: 2em;
        transition: 300ms;
      }
      .desktopSteeringButton:hover {
        background-color: var(--backgroundcolorHover);
      }
      .loadDivs {
        background-color: var(--backgroundcolor);
        border-radius: 1dvw;
        border: none;
        display: flex;
        justify-content: center;
        align-items: center;
        font-size: 2em;
        transition: 200ms;
      }

      #bildContainer {
        grid-row: 1 / 6;
        grid-column: 1 / 5;
        display: flex;
        justify-content: center;
        align-items: center;
      }
      #fadenkreuzContainer {
        width: 2dvw;
        aspect-ratio: 1/1;
        position: absolute;
        display: flex;
        justify-content: center;
        align-items: center;
      }

      #img {
        display: block;
        user-select: none;
        background-color: var(--backgroundcolor);
        width: 100%;
        height: 100%;
        transition: 200ms;
        border-radius: 1dvw;
      }

      #fakten {
        grid-column: 5/7;
        grid-row: 1/7;
        display: flex;
        flex-direction: column;
        justify-content: start;
        flex-shrink: 0;
        padding-top: 2dvw;
      }

      ul {
        font-size: 1.6dvw;
        width: 80%;
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
        font-size: 1.5dvw;
        font-weight: 300;
        color: var(--linsenPodcolor);
        padding-right: 0.5vw;
      }
      #curiosityBanner {
        font-size: 3dvw;
      }

      #big {
        border-radius: 0;
        width: 100dvw;
        height: 100dvh;
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
        width: 60dvw;
        height: 70dvh;
        position: relative;
        display: flex;
        justify-content: space-between;
        align-items: start;
        padding: 1dvw;
        animation-name: menuOpenAnimation;
        animation-duration: 150ms;
        animation-timing-function: linear;
        background-color: var(--backgroundcolor);
        border-radius: 1dvw;
        
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
        font-size: 2dvw;
        font-weight: bolder;
        width: 3dvw;
        height: 3dvw;
        background-color: var(--backgroundcolorHover);
        display: flex;
        justify-content: center;
        align-items: center;
      }

      #logoinfo {
        width: 5dvw;
        height: 5dvw;
        margin: 1dvw;
      }

      #lilBigHeader {
        width: 100%;
        display: flex;
        justify-content: space-between;
      }
      #lilBigHeaderBanner{
        display: flex;
        justify-content: center;
        align-items: center;
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
        border-radius: 0.5dvw;
        padding: 0.5dvw;
        margin-bottom: 0.5dvw;
      }
      #themeLabel {
        font-size: 1.5rem;
      }

      #desktopDivNr2{
        grid-column: 1/3;
        grid-row: 6/8;
        display: flex;
      }
      #info {
        width: 100%;
        font-size: 1rem;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        position: absolute;
        bottom: 1dvw;
      }
      select {
        background-color: var(--backgroundcolor);
        border: 2px solid var(--backgroundcolorHover);
        border-radius: 0.5dvw;
        font-size: 1.5rem;
      }
      .buttons {
        transition: 200ms;
      }
      .buttons:hover {
        background-color: var(--backgroundcolorHover);
      }

      #settingsConatiner {
        width: calc(100% - 2vw);
        height: calc(100% - 2vw);
        padding: 1dvw;
        display: flex;
        justify-content: end;
        align-items: end;
        position: static;
        top: -10vh;
        
      }
      #settings{
        background-color: transparent;
        transition: 300ms;
        border: none;
      }

      #settings:hover {
        transform: rotateZ(90deg);
        scale: 1.1;
      }

      .loadDivs {
        animation: load 500ms ease-out 1;
      }

      @keyframes load {
        0% {
          transform: translateY(30vh);
          opacity: 0;
        }
        100% {
          transform: translateY(0);
          opacity: 1;
        }
      }

    /* Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles*/
    /* Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles*/
    /* Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles-Mobile Styles*/

    #mobileSteeringSite{
        width: 98dvw;
        height: calc(100dvh - 2dvw);
        background-color: var(--bodybackgroundcolor);
        padding: 1vw;
        gap: 1vw;
        display: none;
        

    }
    #mobileBildContainer{
        width: 90dvw;
        background-color: var(--backgroundcolor);
        display: flex;
        justify-content: center;
        align-items: center;
    }
    
    #mobileImg{
        display: block;
        user-select: none;
        background-color: var(--backgroundcolor);
        width: 100%;
        height: 100%;
        transition: 200ms;
        border-radius: 1dvw;
    }
    #mobileFadenkreuzContainer{
        width: 85dvw;
        height: calc(100dvh - 2dvw);
        position: absolute;
        display: flex;
        justify-content: space-between;
        align-items: center;
        padding: 0;
    }

    .mobileDivInsideImg{
      height: calc(100% - 2dvw);
      width: 18dvw;
      padding: 1dvw;
    }

    #mobileBeschleunigungsButtonDiv{
      display: flex;
      justify-content: start;
      align-items: center;
    }
    #mobileBeschleunigungsButtonDivDiv{
      width: 10dvw;
      height: 70dvh;
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
      padding: 1dvw;
      gap: 1vw;
    }

    .mobileAccelerationButton{
      height: 100%;
      width: 100%;
      border-radius: 1vw;
      border: none;
      background-color: rgba(0, 0, 0, 0.2);
      backdrop-filter: blur(10px);
      font-size: 4rem;
      font-weight: 900;
      display: flex;
      justify-content: center;
      align-items: center;

    }
    
    #mobileSliderSteeringDiv{
      display: flex;
      justify-content: center;
      align-items: end;
      padding: 1vw;
      height: calc(100% - 5.5vw);
      padding-bottom: 5vw;
      padding-left: 0;
    }

    #mobileSliderSteering{
      width: 90%;
      -webkit-appearance: none; 
      appearance: none;
      background: transparent;
      margin: 0;
    }


    #mobileSliderSteering::-webkit-slider-runnable-track {
      width: 100%;
      height: 4.1vw;
      background: var(--backgroundcolor);
      border-radius: 2.2vw;
      border: none;
      }

    #mobileSliderSteering::-webkit-slider-thumb {
      -webkit-appearance: none;
      appearance: none;
      height: 4vw;
      width: 4vw;
      background-color: var(--fontcolor);
      border-radius: 50%;
      position: relative;
      
    }

    #mobileFadenkreuzDiv{
      display: flex;
      justify-content: center;
      align-items: center;
    }

    #mobileOtherContent{
        height: calc(100% - 2dvw);
        width: 10%;
        background-color: var(--backgroundcolor);
        padding: 1dvw;
        display: grid;
        grid-template-columns: 1fr;
        grid-template-rows: 1fr 1fr 1fr 1fr 1fr;
    }

    .mobileButtonOrDivs{
        background-color: var(--backgroundcolor);
        font-size: 2dvw;
        padding: 1dvw;
        border-radius: 1dvw;
        display: flex;
        justify-content: center;
        align-items: center;
        border: 2px solid var(--fontcolor);
    }

    .mobileLoadDivs{
        animation: load 500ms ease-out 1;
    }
    #mobileDriveButton{
        background-color: rgba(60, 255, 0, 0.2);
    }
    #mobileBannerLogoDiv{
        border: none;
    }
    #mobileBannerLogo{
        border: none;
        height: 15dvh;
        aspect-ratio: 1/1;
    }
    #askGyroskopePermissionDiv{
      display: none;
      background-color: var(--backgroundcolor);
      width: 50dvw;
      height: 60dvh;
    }
     </style>
  </head>
  <body id="body">
    <div id="bodyContentAskDivice">
      <div id="askDiviceDiv" class="requeststBeforSteeringSite">
        <h1 id="askDiviceH1">What are you using?</h1>
        <div>
          <button class="askDiviceButton" onclick="loadDesktop()">Desktop</button>
          <button class="askDiviceButton" onclick="loadMobile()">Mobile</button>
        </div>
      </div>
      
    </div>

    <div id="desktopSteeringSite">
        <div class="loadDivs" id="fakten">
          <h4>Anleitung:</h4>
          <ul>
            <li>WASD - vorwärts, links, rückwärts, rechts
            <li>Pfeil rechts - höhere Geschwindigkeitsstufe</li>
            <li>Pfeil links - niedrigere Geschwindigkeitsstufe</li>
            <li>Pfeil oben/unten - Kamera entsprechend schwenken</li>
          </ul>
          <h4>Fakten:</h4><ul>
            <li>maximale Geschwindigkeit: 5km/h</li>
            <li>Zugkraft: 5 Newton</li>
            <li>Gewicht: 400g</li>
            <li>Höhe: 20cm</li>
            <li>Breite: 20cm</li>
            <li>Länge: 30cm</li>
            <li>Empfang: definiert nach Reichweite des benutzten Netzwerks</li>
          </ul>
          
          <div id="settingsConatiner">
            <button id="settings" onclick="openMenu()"><img id="settingIcon" src="https://squidpod.github.io/images/pics/settings%20forDarkmode.png" alt="" width="50"></button>
          </div>
          </div>
          <div class="loadDivs" id="desktopDivNr2">2</div>
      
          <div class="loadDivs" id="bildContainer">
            <div id="fadenkreuzContainer">
              <img src="https://squidpod.github.io/images/pics/aim_Dark.png" alt="" width="50" id="crosshair">
            </div>
            <img id="img" src="http://192.168.18.168:8080/video" />
          </div>
          
          <button class="desktopSteeringButton loadDivs" id="w" onclick="sendButtonState('honk')">
            HUPE
          </button>
          <button class="desktopSteeringButton loadDivs" id="a" onclick="sendButtonState('p')">
            shoot
          </button>
          <div class="loadDivs" id="counterDisplay">Speed: <span id="counter">4</span>/7</div>
          <div class="loadDivs" id="testFürWASD">1</div>
          <!--Menu(z.B. Dark/Lightmode)-Menu(z.B. Dark/Lightmode)-Menu(z.B. Dark/Lightmode)-Menu(z.B. Dark/Lightmode)--->
          <div class="loadDivs" id="big" class="loadDivs">
            <div id="lilBig">
              <div id="lilbigcontent">
                <div id="lilBigHeader">
                  <div id="lilBigHeaderBanner">
                    <img
                      id="logoinfo"
                      src="https://squidpod.github.io/images/pics/final_light.png"
                    />
                    <h5 id="linsenpodBanner">LinsenPod</h5>
                    <h3 id="curiosityBanner"><b>Curiosity</b></h3>
                  </div>
                  <button class="desktopSteeringButton" id="lilBigButton" onclick="hideMenu()">
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
          <div loadDivs class="button loadDivs" id="banner" >
            <h5 id="linsenpodBanner">LinsenPod</h5>
            <h3 id="curiosityBanner"><b>Curiosity</b></h3>
          </div>
    </div>

    <div id="mobileSteeringSite">
        <div class="loadDivs" id="mobileBildContainer">
            <div id="mobileFadenkreuzContainer">
              <div class="mobileDivInsideImg" id="mobileBeschleunigungsButtonDiv"><div id="mobileBeschleunigungsButtonDivDiv"><button class="mobileAccelerationButton" ontouchstart="mobileBeschleunigungPlusDown()" onmousedown="mobileBeschleunigungPlusDown()" ontouchend="mobileBeschleunigungPlusRelease()" onmouseup="mobileBeschleunigungPlusRelease">+</button><button class="mobileAccelerationButton" ontouchstart="mobileBeschleunigungMinusDown()" onmousedown="mobileBeschleunigungMinusDown()" ontouchend="mobileBeschleunigungMinusRelease()" onmouseup="mobileBeschleunigungMinusRelease()">-</button></div></div>
              <div class="mobileDivInsideImg" id="mobileFadenkreuzDiv"><img src="https://squidpod.github.io/images/pics/aim_Dark.png" alt="" width="50" id="crosshair"></div>
              <div class="mobileDivInsideImg" id="mobileSliderSteeringDiv"><input id="mobileSliderSteering" type="range" min="1" max="3"></div>
            </div>
            <img id="mobileImg" src="http://192.168.18.168:8080/video" />
          </div>


          <div id="mobileOtherContent" class="loadDivs">
            <button id="mobileDriveButton" class="mobileButtonOrDivs mobileLoadDivs" onclick="driveMode()">Drive</button>
            <button class="mobileButtonOrDivs mobileLoadDivs" onclick="mobileSpeedUp()">+</button>
            <button class="mobileButtonOrDivs mobileLoadDivs" onclick="mobileSpeedDown()">-</button>
            <button id="betaGamma" class="mobileButtonOrDivs mobileLoadDivs">Hello</button>
            <div id="mobileBannerLogoDiv"  class="mobileButtonOrDivs mobileLoadDivs"><img id="mobileBannerLogo" src="https://squidpod.github.io/images/pics/final_light.png" alt=""></div>
          </div>
          
    </div>
    <script>

      function mobileBeschleunigungPlusDown(){
        sendButtonState("w");
        console.log("w");
      }
      
      function mobileBeschleunigungPlusRelease(){
        sendButtonState("w_release");
        console.log("w_release");
      }


      function mobileBeschleunigungMinusDown(){
        sendButtonState("s");
        console.log("s");

      }

      function mobileBeschleunigungMinusRelease(){
        sendButtonState("s_release");
        console.log("s_release");

      }

      function mobileSpeedDown(){
        sendButtonState("ArrowLeft");
        console.log("speed down");
      }
      function mobileSpeedUp(){
        sendButtonState("ArrowRight");
        console.log("speed up");
      }

    




    


//loadingFunctions
      const body = document.getElementById("body");
      const bodyContentAskDivice = document.getElementById(
        "bodyContentAskDivice"
      );
      const desktopSteeringSite = document.getElementById(
        "desktopSteeringSite"
      );
      const mobileSteeringSite = document.getElementById('mobileSteeringSite');

      const askDiviceDiv = document.getElementById("askDiviceDiv");
      
      const mobileDriveButton = document.getElementById("mobileDriveButton");
      let currentlyDriving = false;

      function loadDesktop() {
        bodyContentAskDivice.style = "display: none;";
        desktopSteeringSite.style = "display: grid;";
      }

      function loadMobile(){
        bodyContentAskDivice.style = "display: none;";
        mobileSteeringSite.style.display = 'flex';
      }

      
     //rgba(60, 255, 0, 0.2)
      function driveMode(){
        if(!currentlyDriving){
          mobileDriveButton.innerText = "stopp";
          mobileDriveButton.style.backgroundColor = "rgba(255, 0, 0, 0.2)";
          currentlyDriving = true;
        }
        else{
          mobileDriveButton.innerText = "Drive";
          mobileDriveButton.style.backgroundColor = "rgba(60, 255, 0, 0.2)";
          currentlyDriving = false;
        }
      }


      //old JavaScript

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
      const crosshair = document.getElementById('crosshair');
      const settings = document.getElementById('settingIcon');

      const darkModeSettingsIcon = "https://squidpod.github.io/images/pics/settings%20forDarkmode.png";
      const lightModeSettingsIcon = "https://squidpod.github.io/images/pics/settings%20forLightMode.png";

      const lightCrosshairSource = "https://squidpod.github.io/images/pics/aim_Light.png";
      const darkCrosshairSource = "https://squidpod.github.io/images/pics/aim_Dark.png";

      function lightDark(dark) {
        if (dark == "true") {
          settings.src = darkModeSettingsIcon;

          crosshair.src = darkCrosshairSource;

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
          settings.src = lightModeSettingsIcon;
          crosshair.src = lightCrosshairSource;


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
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="preconnect" href="https://fonts.googleapis.com" />
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
    <link
      href="https://fonts.googleapis.com/css2?family=Fredoka:wght@300..700&display=swap"
      rel="stylesheet"
    />
    <title>ESS Curiosity</title>
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
      }

      body {
        overflow-x: hidden;
        padding: 2vw;
        display: flex;
        flex-direction: column;
        align-items: center;
        color: var(--fontcolor);
        background-color: var(--bodybackgroundcolor);
      }
      h1 {
        font-size: 3.5vw;
      }

      button {
        background-color: var(--backgroundcolor);
        border: none;
        border-radius: calc(10px + 1.5vw);
        color: var(--fontcolor);
      }
      ul {
        font-size: calc(10px + 1.5vw);
      }
      p {
        font-size: calc(10px + 1.3vw);
      }
      img {
        width: 7vw;
        aspect-ratio: 1/1;
        padding-right: 1vw;
      }

      #banner {
        display: flex;
        justify-content: center;
        align-items: center;
        height: 30vh;
      }

      #linsenpod {
        font-size: calc(10px + 3.5vw);
        font-weight: 400;
        color: var(--linsenPodcolor);
      }

      #Curiosity {
        font-size: calc(10px + 6vw);
      }

      #ausprobieren {
        padding: 2vw 3vw;
        background-color: var(--backgroundcolor);
        border-radius: calc(10px + 1.5vw);
        box-shadow: 0 0 4vw black;
        color: var(--fontcolor);
      }
      a {
        text-decoration: none;
      }

      #info {
        margin-top: 5vw;
        width: 60vw;
        background-color: var(--backgroundcolor);
        border-radius: calc(10px + 1.5vw);
        padding: 2vw 3vw;
        padding-bottom: 0;
        display: flex;
        flex-direction: column;
        align-items: center;
        box-shadow: 0 0 4vw black;
      }

      #idee {
        margin: 0;
        padding: 0;
      }
      #githublink {
        transition: 200ms;
        color: var(--fontcolor);
        text-decoration: underline;
        font-size: calc(13px + 0.7vw);
      }
      #githublink:hover {
        transform: scale(1.1);
      }
      #copyright {
        font-size: calc(10px + 0.5vw);
        text-align: center;
      }

      ::-webkit-scrollbar {
        width: 12px;
        height: 12px;
      }

      ::-webkit-scrollbar-track {
        background: transparent;
        border-radius: 10px;
      }

      ::-webkit-scrollbar-thumb {
        background-color: var(--backgroundcolor);
        border-radius: 10px;
      }

      ::-webkit-scrollbar-thumb:hover {
        background-color: #555;
      }
    </style>
  </head>
  <body id="body">
    <div id="banner">
      <img src="https://squidpod.github.io/images/pics/final_dark.png" />
      <h3 id="linsenpod">LinsenPod</h3>
      <h1 id="Curiosity"></h1>
    </div>
    <a href="/drivepanel">
      <h1 id="ausprobieren">Hier gehts zu Steuerung</h1>
    </a>

    <div id="info">
      <h1>Unsere Idee:</h1>
      <div id="idee">
        <p>
          Curiosity ist ein Auto, das über eine Website gesteuert wird, auf der
          ein Livebild von einer Handykamera zu sehen ist, die sich auf dem Auto
          befindet. Die Website läuft auf einem ESP 8266 Mikrokontroller, der
          über WLAN mit einem Browser verbunden werden kann. So kann man das
          Auto überall dort fahren, wo das Auto dasselbe WLAN wie der Browser
          hat. Der Fahrer kann jedoch bequem an einem Platz bleiben.
        </p>
      </div>

      <h1>Tech-Stack:</h1>
      <ul>
        <li>C++</li>
        <li>Html</li>
        <li>CSS</li>
        <li>JavaScript</li>
        <li>Notion Teamspace</li>
        <li>Github</li>
        <li>Arduino IDE</li>
        <li>VS Code</li>
      </ul>
      <a
        href="https://github.com/linse2268/Linsenpod-Curiosity/"
        target="_blank"
        ><h3 id="githublink">Unser Github Repository</h3></a
      >
      <p id="copyright">
        von Rémy Göttlich und Linus Bös im Rahmen des Informatik Unterrichtes
        bei Herrn Hagedorn 2024/2025
      </p>
    </div>

    <script>
      const curiosity = document.getElementById("Curiosity");
      const name = "Curiosity";
      let namePart = "";
      let x = 0;

      const inteval = setInterval(() => {
        namePart = namePart + name[x];
        curiosity.innerText = namePart;
        x++;
        if (x == 9) {
          stopInterval();
        }
      }, 300);

      function stopInterval() {
        clearInterval(inteval);
      }
    </script>
  </body>
</html>

)=====";