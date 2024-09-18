<?php

$hostname = "localhost";
$username = "remy";
$password = "magnus";
$database = "dbnotizen";

$conn = mysqli_connect($hostname, $username, $password, $database);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}


$sql = "select * from tablenotizen";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    // output data of each row
    while($row = mysqli_fetch_assoc($result)) {
      echo $row["id"] . "   -   " . $row["notiz"] . "\n";
    }
} else {
    echo "0 results";
}

mysqli_close($conn);
?>