const telco = require('..');
const { inspect } = require('util');

async function main() {
  const device = await telco.getUsbDevice();
  const applications = await device.enumerateApplications({ scope: 'full' });
  console.log('[*] Applications:', inspect(applications, {
    maxArrayLength: 500,
    depth: 4,
    colors: true
  }));
}

main()
  .catch(e => {
    console.error(e);
  });
