<?hh //partial

class TestContainer extends TestCase {

	private MyContainer $con;
	private Set<IMyPair> $pairs;

        public function __construct() {
                parent::__construct();
                $this->con = new MyContainer();
		$this->pairs = new Set(null);
        }

        public function setUp() :void {
                parent::reset();
                $this->con = new MyContainer();
        }

        public function tearDown() :void {
                $this->con = new MyContainer();
        }

	public function testSet():void {
		$this->con->addString("this is","a test");
		$this->pairs = $this->con->getPairs();
	}
}
