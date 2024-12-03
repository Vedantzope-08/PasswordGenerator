# PasswordGenerator
The program is a robust password generator designed to create strong and secure passwords by taking user inputs such as first name, last name, and birth year. It enhances password security by ensuring specific criteria are met, including a minimum length of 8 characters, the inclusion of at least one capital letter, and the addition of special symbols. The passwords are randomized using a shuffle function to prevent predictable patterns.<br>

Users have the option to regenerate the password if unsatisfied or save it to a MySQL database, which securely stores the passwords along with the user's details. The program utilizes SQL queries to insert data into the database and provides feedback on successful or failed storage operations. It also incorporates platform-specific commands to clear the console for better user interaction during the regeneration process.<br>
# Libraries
iostream<br>
windows.h<br>
mysql.h<br>
sstream<br>
string<br>
cstdlib<br>
ctime<br>
cctype<br>

# Important Functions
  <h3>shuffleString</h3><br>
      Randomizes the order of characters in a given string to enhance unpredictability.
      ensureLength<br>
      Ensures the password is at least 8 characters long by adding random special symbols if necessary.<br>
      
  <h3>ensureCapitalLetter</h3><br>
      Checks if the password contains at least one capital letter and inserts one if missing.<br>
      
  <h3>ensureSymbol</h3><br>
      Ensures the presence of at least one special symbol in the password, adding one if absent.<br>

  <h3>main</h3><br>
      Handles user input, generates passwords, integrates MySQL for saving passwords, and provides an option for regeneration or saving the password.<br>

Link for Reference<br>
link Randomizer:- https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/    <br>
link for SQL Setup :- https://youtu.be/3v_lA1Gg1Q4?feature=shared      <br>
