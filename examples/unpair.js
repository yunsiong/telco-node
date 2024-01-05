const telco = require('..');

async function main() {
  const device = await telco.getUsbDevice();
  await device.unpair();
}

main()
  .catch(e => {
    console.error(e);
  });
