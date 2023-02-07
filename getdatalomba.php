<?php
$host = "localhost";
$user = "id17257013_sefeodatabase";
$pass = "c(*j6gwL2&!5AavL";
$db = "id17257013_sefeo";
$conn = mysqli_connect($host,$user,$pass,$db);
$result_array = array();
$sql = "SELECT * FROM lomba LIMIT = 1 DESC";
$result = mysqli_query($conn,$sql);

if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        array_push($result_array, $row);
    }
}
echo json_encode($result_array);
mysqli_close($con);