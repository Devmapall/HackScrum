<?hh

$pdo = new PDO("mysql:host=localhost;dbname=auth","root","uUQ8h8LY");
$stmt = $pdo->query("SELECT u.username 
FROM systems as s 
INNER JOIN user_systems as us ON (s.ID = us.system_id) 
INNER JOIN user as u ON (us.user_id = u.ID) 
WHERE s.ID = 3;");
for($i=0;$i<$stmt->rowCount();$i++) {
	var_dump($stmt->fetchObject());
}
