<!DOCTYPE html>
<html>

<head>
    <title>Table with database</title>
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

</head>
<body class="bg-light">
   <div class="container">
      <div class="py-5 text-center">
      </div>
      <div class="row">
         <h4 class="mb-3">User Information</h4>
         <div class="table-responsive">
            <?php
               $server_name = "localhost";
               $username = "root";
               $password = "";
               $db_name = "kusims_db";
               
               $conn = mysqli_connect($server_name, $username, $password, $db_name);
               
               // Check connection
               if ($conn->connect_error) {
               	die("Connection failed: " . $conn->connect_error);
               }
               
               $sql = "select * from users";
               
               $result = $conn->query($sql);
               echo "<table class='table table-striped table-sm'>
               <tr>
               	<th>Id</th>
               	<th>FIRST NAME</th>
               	<th>LAST NAME</th>
               	<th>USER TYPE</th>
               	<th>EMAIL</th>
               </tr>";
               
               if ($result->num_rows > 0) {
               
               	while ($row = $result->fetch_assoc()) {
               		echo "<tr>";
               			echo "<td>" . $row['id'] . "</td>";
               			echo "<td>" . $row['first_name'] . "</td>";
               			echo "<td>" . $row['last_name'] . "</td>";
               			echo "<td>" . $row['user_type'] . "</td>";
               			echo "<td>" . $row['email'] . "</td>";
               		echo "</tr>";
               	}
               	echo "</table>";
               }
               
               $conn->close();
               ?>
         </div>
      </div>
   </div>
</body>
</html>