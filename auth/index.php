<?hh
if(!isset($_COOKIE["sso"])) {
	 if(isset($_POST["username"]) && isset($_POST["password"])) {
		auth($_POST["username"],$_POST["password"]);
	 }
} else {
	validate($_COOKIE["sso"]);
}

function auth($user,$pass) {
	$resource = curl_init("http://auth.mykey.to:8080/index.php");
	curl_setopt($resource, CURLOPT_POST, 1);
	curl_setopt($resource, CURLOPT_POSTFIELDS, array("username"=>$user,"password"=>$pass));
	curl_setopt($resource, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($resource, CURLOPT_CURLINFO_HEADER_OUT, 1);
	curl_setopt($resource, CURLOPT_HTTPHEADER, array("Origin: http://scrum.mykey.to"));
	$result = curl_exec($resource);
	$json = json_decode($result);
	if($json->Result) {
		setcookie("sso",$json->SESSID,time()+60*24*2,"/",".mykey.to");
		echo json_encode(array("Result"=>true));
	}
}

function validate($sso) {
	$pdo = new PDO("mysql:host=localhost;dbname=auth;","root","uUQ8h8LY");
	$sql = "SELECT s.ID, u.username FROM sessions as s INNER JOIN user as u ON (s.user_id = u.ID) WHERE s.ID = '".$sso."';";
	$stmt = $pdo->query($sql);
	if($stmt->rowCount() > 0) {
		$var = $stmt->fetchObject();
		echo json_encode(array("valid"=>true,"username"=>$var->username));
	}
}
