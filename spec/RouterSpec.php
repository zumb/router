<?hh //partial

namespace spec\Zumb\Routing;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

class RouterSpec extends ObjectBehavior
{
    public function it_loads_resource_uri()
    {
        $this->load("/users/john/pictures/23");
        $this->getTarget()
          ->shouldReturn("Users\\Pictures");
        $this->getParameters()
          ->shouldReturn(["john", "23"]);
        $this->isResource()
          ->shouldReturn(true);
    }

    public function it_loads_folder_uri()
    {
        $this->load("/users/john/pictures");
        $this->getTarget()
          ->shouldReturn("Users\\Pictures");
        $this->getParameters()
          ->shouldReturn(["john"]);
        $this->isResource()
          ->shouldReturn(false);
    }
}
