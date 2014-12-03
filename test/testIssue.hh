<?hh //partial

class TestIssue extends TestCase {

	private Issue $issue;

        public function __construct() {
                parent::__construct();
                $this->issue = new Issue();
        }

        public function setUp() :void {
                parent::reset();
                $this->issue = new Issue();
        }

        public function tearDown() :void {
                $this->issue = new Issue();
        }

	public function testID() {
            $this->assertEqualsInt($this->issue->getID(),-1);
            $this->issue->setID(539);
            $this->assertEqualsInt($this->issue->getID(),539);
        }
}
