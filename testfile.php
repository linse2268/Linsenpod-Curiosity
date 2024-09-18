<?php

$hostname = "localhost";
$username = "remy";
$password = "magnus";
$database = "dbnotizen";

$conn = mysqli_connect($hostname, $username, $password, $database);
echo "hallo";

if (!$conn) {
    die("connection failed: ".mysqli_connect_error());
}

$t = $_GET["fdata"];


$sql = "insert into tablenotizen (notiz) values ('$t')";
if(mysqli_query($conn, $sql)) {

    echo "\nnew record created";

}  else {

echo "error: ".$sql."<br>".mysqli_error($conn);

}



mysqli_close($conn);

?>