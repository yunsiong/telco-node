const telco = require('..');
const util = require('util');

async function main() {
  const device = await telco.getDevice('xyz:lockdown');

  console.log('Getting channel...');
  // const channel = await device.openChannel('tcp:1234');
  const channel = await device.openChannel('lockdown:com.apple.instruments.remoteserver');
  console.log('Got channel:', util.inspect(channel, {
    colors: true,
    breakLength: Infinity
  }));
}

main()
  .catch(e => {
    console.error(e.stack);
  });
