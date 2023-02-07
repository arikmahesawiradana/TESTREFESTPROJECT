<?php
$host = "localhost";
$user = "id17257013_sefeodatabase";
$pass = "c(*j6gwL2&!5AavL";
$db = "id17257013_sefeo";
$conn = mysqli_connect($host,$user,$pass,$db);
$vdc = rand(46, 47);
$vac = rand(46, 47);
$vin = rand(219, 221);
$adc = rand(1,2);
$aac = rand(1,2);
$ain = rand(2,3);
$sql = "UPDATE lomba SET vdc='$vdc',
        vac='$vac',
        vin='$vin',
        adc='$adc',
        aac='$aac',
        ain='$ain'";
if ($conn->query($sql) === TRUE) {
    echo "SERVER IS RUNNING";
    } else {
    echo "SERVER IS DOWN";
    }
    $conn->close();
?>