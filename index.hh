<?hh //partial

//TODO: Check user permissions!
require_once "src/config.hh";

if(isset($_POST['action'])) {

	require_once "src/facade.hh";
	$action = $_POST['action'];
        $sso = $_COOKIE['sso'];
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
                case "getProjects": $facade->getProjects($sso);
                break;
                case "getSeverities": $facade->getSeverities();
                break;
                case "getPriorities": $facade->getPriorities();
                break;
                case "getStatuses": $facade->getStatuses();
                break;
                case "addIssue": $facade->addIssue($_POST["project"], $_POST["severity"], $_POST["priority"], $_POST["title"], $_POST["text"], $sso);
                break;
                case "addTask": $facade->addTask($_POST["project"], $_POST["severity"], $_POST["priority"], $_POST["title"], $_POST["text"], $sso);
                break;
                case "getMyIssues": $facade->getIssuesByUser($sso);
                break;
                case "getMyTasks": $facade->getTasksByUser($sso);
                break;
                case "getUnassignedIssues": $facade->getUnassignedIssues();
                break;
                case "getIssue": $facade->getIssueByID((int)$_POST["ID"]);
	}

}
