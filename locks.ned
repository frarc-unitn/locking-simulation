//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

moduleinterface Node
{
    parameters:
        double requestInterval @unit(ms);
        double workDelay @unit(ms);

    gates:
        inout link;
}

simple OptimisticNode like Node
{
    parameters:
        double requestInterval @unit(ms);
        double workDelay @unit(ms);

    gates:
        inout link;
}

simple PessimisticNode like Node
{
    parameters:
        double requestInterval @unit(ms);
        double workDelay @unit(ms);

    gates:
        inout link;
}

moduleinterface Manager
{
    gates:
        inout nodes[];
}

simple OptimisticManager like Manager
{
    gates:
        inout nodes[];
}

simple PessimisticManager like Manager
{
    parameters:
        volatile double lockDelay @unit(ms);

    gates:
        inout nodes[];
}

network locking_scenario
{
    parameters:
        string locking_type;

    submodules:
        nodes[2]: <locking_type + "Node"> like Node;
        manager: <locking_type + "Manager"> like Manager;
    connections:
        nodes[0].link <--> manager.nodes++;
        nodes[1].link <--> manager.nodes++;
}
