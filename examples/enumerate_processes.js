const telco = require('..');
const { inspect } = require('util');

async function main() {
  const device = await telco.getUsbDevice();
  const processes = await device.enumerateProcesses({ scope: 'full' });
  console.log('[*] Processes:', inspect(processes, {
    maxArrayLength: 500,
    depth: 4,
    colors: true
  }));
}

main()
  .catch(e => {
    console.error(e);
  });
