from subprocess import PIPE, Popen, run
from pathlib import Path
import pytest


ROOT = Path(__file__).parent.parent  # test/ → ../

test_string = [
    "Hello",
    "123456",
    "asasdfd",
    "bb\nff",
    "A" * 100, # check
]


@pytest.fixture
def start_server():
    proc = Popen(["./server"], cwd=ROOT, stdout=PIPE, text=True)
    pid_server = proc.pid

    yield proc, pid_server
    proc.terminate()
    proc.wait()


@pytest.mark.parametrize("message", test_string)
def test_start_client(start_server, message):
    proc, pid_server = start_server
    run(["./client", str(pid_server), message], cwd=ROOT, check=True)
    _ = proc.stdout.readline() # pid
    output = ""
    for _ in range(len(message)):
        output += proc.stdout.read(1)
    print(output)
    assert message == output
