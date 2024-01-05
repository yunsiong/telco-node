const telco = require('..');

async function main() {
  const device = await telco.getRemoteDevice();

  const session = await device.attach('hello2');
  await session.setupPeerConnection({
    stunServer: 'telco.re:1336',
    relays: [
      new telco.Relay({
        address: 'telco.re:1337',
        username: 'foo',
        password: 'hunter2',
        kind: 'turn-udp'
      }),
      new telco.Relay({
        address: 'telco.re:1338',
        username: 'bar',
        password: 'hunter3',
        kind: 'turn-tcp'
      }),
      new telco.Relay({
        address: 'telco.re:1339',
        username: 'baz',
        password: 'hunter4',
        kind: 'turn-tls'
      }),
    ]
  });
  console.log('Success!');
}

main()
  .catch(e => {
    console.error(e);
  });
