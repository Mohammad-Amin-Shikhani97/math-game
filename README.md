<h1>Math Game</h1>

<p>
A simple command-line mathematics quiz game written in C++. The game generates random math problems and lets you practice addition, subtraction, multiplication, and division at different difficulty levels.
</p>

<h2>Table of Contents</h2>
<ol>
  <li><a href="#features">Features</a></li>
  <li><a href="#prerequisites">Prerequisites</a></li>
  <li><a href="#installation">Installation</a></li>
  <li><a href="#usage">Usage</a></li>
  <li><a href="#game-flow">Game Flow</a></li>
  <li><a href="#references">References</a></li>
  <li><a href="#license">License</a></li>
</ol>

<h2 id="features">Features</h2>
<ul>
  <li><strong>Multiple difficulty levels:</strong> Easy, Medium, Hard, and Mix (random difficulties).</li>
  <li><strong>Multiple operations:</strong> Addition, Subtraction, Multiplication, and Division.</li>
  <li><strong>Configurable number of questions:</strong> Choose between 1 and 10 questions.</li>
  <li><strong>Scoring:</strong> See how many questions you answered correctly and whether you passed or failed.</li>
  <li><strong>Replay option:</strong> Prompt to play again or exit after each complete run.</li>
</ul>

<h2 id="prerequisites">Prerequisites</h2>
<ul>
  <li>A C++ compiler (e.g., <a href="https://gcc.gnu.org/" target="_blank">GCC</a>, <a href="https://clang.llvm.org/" target="_blank">Clang</a>, or Microsoft Visual C++).</li>
  <li><a href="https://cmake.org/" target="_blank">CMake</a> (optional, only if you choose to build with CMake).</li>
</ul>
<p><em>Note:</em> If you are using a modern C++ environment, make sure you have C++11 or higher to ensure compatibility with standard library functions.</p>

<h2 id="installation">Installation</h2>
<ol>
  <li><strong>Clone the repository:</strong></li>
</ol>
<pre><code>git clone https://github.com/Mohammad-Amin-Shikhani97/math-game.git
</code></pre>
<ol start="2">
  <li><strong>Navigate to the project directory:</strong></li>
</ol>
<pre><code>cd math-game
</code></pre>
<ol start="3">
  <li><strong>Compile the code</strong> (using a simple g++ command):</li>
</ol>
<pre><code>g++ -o MathGame main.cpp
</code></pre>
<p>Or, if you have the file named differently (e.g., <code>MathGame.cpp</code>), adapt the command accordingly:</p>
<pre><code>g++ -o MathGame MathGame.cpp
</code></pre>
<ol start="4">
  <li><strong>Run the compiled executable:</strong></li>
</ol>
<pre><code>./MathGame
</code></pre>

<h2 id="usage">Usage</h2>
<ol>
  <li>Upon running the game, you will be asked:
    <ul>
      <li><strong>How many questions</strong> you want to solve (between 1 and 10).</li>
      <li><strong>Difficulty level</strong> (1 = Easy, 2 = Medium, 3 = Hard, 4 = Mix).</li>
      <li><strong>Operation type</strong> (1 = Add, 2 = Sub, 3 = Mul, 4 = Div).</li>
    </ul>
  </li>
  <li>The program will then generate random math questions. Enter your answers when prompted.</li>
  <li>After each question:
    <ul>
      <li>The terminal color will change depending on whether the answer was correct or incorrect.</li>
      <li>You will see a short summary indicating if your answer was correct and, if not, what the correct answer was.</li>
    </ul>
  </li>
  <li>At the end of the quiz, you’ll get:
    <ul>
      <li>The total number of questions.</li>
      <li>The difficulty level you chose.</li>
      <li>The type of math operation.</li>
      <li>How many questions you answered correctly.</li>
      <li>How many were answered incorrectly.</li>
      <li>A pass or fail status based on whether your correct answers exceed your incorrect ones.</li>
    </ul>
  </li>
  <li>You will then be prompted to <strong>play again</strong> (<code>Y</code>) or <strong>exit</strong> (<code>N</code>).</li>
</ol>

<h2 id="game-flow">Game Flow</h2>
<p>
Below is a simplified overview of how the code works internally:
</p>
<ol>
  <li><strong>StartGame()</strong>:
    <ul>
      <li>Resets the screen, color, and counters.</li>
      <li>Calls <code>Play()</code> in a loop until the user chooses to exit.</li>
    </ul>
  </li>
  <li><strong>Play()</strong>:
    <ul>
      <li>Reads the user’s game settings (number of questions, difficulty, and operation type).</li>
      <li>For each question:
        <ul>
          <li>Randomly generates two numbers (<code>generateNumber()</code> function).</li>
          <li>Calculates the correct result (<code>rightResult()</code> function).</li>
          <li>Prompts user for an answer and checks correctness (<code>isRight()</code> function).</li>
          <li>Adjusts the terminal color based on correctness.</li>
          <li>Increments the correct answer counter if the user’s answer is correct.</li>
        </ul>
      </li>
      <li>Determines pass or fail status and prints a summary of the session.</li>
    </ul>
  </li>
  <li><strong>Random Number Generation</strong>:
    <ul>
      <li>Uses <code>srand()</code> and <code>rand()</code> from the C standard library for pseudo-random number generation.</li>
      <li>Depending on difficulty, the range of generated numbers changes (e.g., 1–10 for Easy, 11–50 for Medium, etc.).</li>
    </ul>
  </li>
</ol>

<h2 id="license">License</h2>
<p>
This project is released under the 
<a href="https://opensource.org/licenses/MIT" target="_blank">MIT License</a>.
You can freely use, modify, and distribute the code for personal or commercial projects.
</p>

<p><strong>Enjoy practicing math with this game!</strong> If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.</p>
