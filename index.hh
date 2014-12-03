<?hh //partial

date_default_timezone_set("Europe/Berlin");)

//TODO: Check user permissions!
require_once "runtime.hh";

if(isset($_POST['action'])) {

	require_once "src/facade.hh";
	$action = $_POST['action'];
	$facade = new ScrumFacade();

	switch($action) {
		case "getUser": $facade->getUser();
		break;
		case "addProject": $vec = Vector {};
					foreach($_POST["projectParticipants"] as $p) {
						$vec[] = $p;
					}
					$facade->addProject($_POST["projectName"],$_POST["projectDescription"],$_COOKIE["sso"],$vec);
		break;
	}

}
