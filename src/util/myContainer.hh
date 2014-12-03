<?hh //strict

class MyContainer {

	private Set<IMyPair> $set;

	public function __construct() {
		$this->set = new Set(null);
	}

	public function addString(string $key, string $val):void {
		$p = new MyPair($key,$val);
		$this->set->add($p);
	}

	public function addInt(string $key, int $val):void {
		$p = new MyPair($key,$val);
		$this->set->add($p);
	}

	public function getPairs():Set<IMyPair> {
		return $this->set;
	}
}
