<?hh //partial

class TestProjectGateway extends TestCase {

	private ProjectGateway $gate;
        private User $user;

        public function __construct() {
            parent::__construct();
            $this->gate = new ProjectGateway();
            $this->user = new User();
        }

        public function setUp() :void {
            parent::reset();
            $this->gate = new ProjectGateway();
            $this->user = new User();
        }

        public function tearDown() :void {
            $this->gate = new ProjectGateway();
            $this->user = new User();
        }

	public function testGetProjectsByUser() {
            $this->user->setID(1);
            $vec = $this->gate->getByUser($this->user);
            assertEqualsString($vec[1],"Hack IDE");
        }
}