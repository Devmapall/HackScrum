<?hh //strict

class Project {

        private int $ID;
	private string $title;
	private string $description;
	private Vector<User> $participants;
	private User $owner;
	private UserFactory $userfac;

	public function __construct() {
                $this->ID = -1;
		$this->title = "";
		$this->description = "";
		$this->participants = Vector {};
		$this->owner = new User();
		$this->userfac = new UserFactory();
	}
        
        public function setID(int $ID) :void {
                $this->ID = $ID;
        }

	public function setTitle(string $title) :void {
		$this->title = $title;
	}

	public function setDescription(string $desc) :void {
		$this->description = $desc;
	}

	public function addParticipants(Vector<User> $participants) :void {
		foreach($participants as $k=>$v) {
			$this->participants[] = $v;
		}
	}

	public function setProjectOwnerByCookie(string $sso) :void {
		$this->owner = $this->userfac->getUserBySSO($sso);
	}

        public function setOwnerByID(int $id) :void {
                $this->owner = $this->userfac->getUserByID($id);
        }

        public function getID() :int { return $this->ID; }
	public function getTitle() :string { return $this->title; }
	public function getDescription() :string { return $this->description; }
	public function getParticipants() :Vector<User> { return $this->participants; }
	public function getOwner() :User { return $this->owner; }
}
