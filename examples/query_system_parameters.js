const telco = require('..');

async function main() {
  console.log('Local parameters:', await telco.querySystemParameters());

  const device = await telco.getUsbDevice();
  console.log('USB device parameters:', await device.querySystemParameters());
}

main()
  .catch(e => {
    console.error(e);
  });
