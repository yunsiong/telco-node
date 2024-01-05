const telco = require('..');
const { inspect } = require('util');

async function main() {
  const device = await telco.getUsbDevice();
  const application = await device.getFrontmostApplication({ scope: 'full' });
  console.log('[*] Frontmost application:', inspect(application, {
    depth: 3,
    colors: true
  }));
}

main()
  .catch(e => {
    console.error(e);
  });
